#include <QDebug>
#include "alarm.h"

void AlarmModel::update()
{
    noRepeateOff();
    m_alarms.clear();
    m_file.open(QFile::ReadOnly);
    if (m_file.exists()) {
        QDataStream in(&m_file);
        int time, week;
        bool repeat, open, isOn;
        while (!m_file.atEnd()) {
            in >> time >> week >> repeat >> open >> isOn;
            Alarm a(time, week, repeat, open, isOn);
            m_alarms.append(a);
        }
    }
    m_file.close();
    m_jalousi->file();
}

void AlarmModel::setZap(int num, const QVariant &value, int role)
{
    m_file.open(QFile::ReadWrite);
    if (m_file.exists()) {
        QDataStream out(&m_file);
        m_file.seek(num * SIZE_ZAP);
        Zap alarm;
        out >> alarm;
        m_file.seek(num * SIZE_ZAP);
        switch (role) {
        case TimeRole:
            out << value.toInt();
            break;
        case WeekRole:
            m_file.seek(m_file.pos() + sizeof(int));
            out << value.toInt();
            break;
        case RepeatRole:
            m_file.seek(m_file.pos() + 2 * sizeof(int));
            out << value.toBool();
            if (alarm.repeat && !value.toBool()) deleteZapNoRepeate(num);   // Если будильник становится повторяющимся то удалить
            if (!alarm.repeat && value.toBool()) {                          // Если будильник становится неповторяющимся то добавить
                ZapNoRepeate zap;
                zap.num = num;
                zap.time = QDateTime().currentDateTime();
                addZapNoRepeate(zap);
            }
            break;
        case OpenRole:
            m_file.seek(m_file.pos() + 2 * sizeof(int) + sizeof(bool));
            out << value.toBool();            
            break;
        case IsOnRole:
            m_file.seek(m_file.pos() + 2 * sizeof(int) + 2 * sizeof(bool));
            out << value.toBool();
            if (!alarm.repeat) {        // Если неповторяющийся будильник включается то изменяем время создания
                ZapNoRepeate zap;
                zap.num = num;
                zap.time = QDateTime().currentDateTime();
                setZapNoRepeate(num, zap);
            }
            break;
        }
    }
    m_file.close();
}

void AlarmModel::noRepeateOff()
{
    m_fileOfNoRepeateAlarms.open(QFile::ReadOnly);
    m_file.open(QFile::ReadWrite);
    if (m_fileOfNoRepeateAlarms.exists() && m_file.exists()) {
        QDataStream file(&m_file);
        QDataStream fileOfNoRepeateAlarms(&m_fileOfNoRepeateAlarms);
        while (!m_fileOfNoRepeateAlarms.atEnd()) {
            ZapNoRepeate zapNoRepeate;
            fileOfNoRepeateAlarms >> zapNoRepeate;
            m_file.seek(zapNoRepeate.num * SIZE_ZAP);
            Zap alarm;
            file >> alarm;
            if (alarm.isOn && !alarm.repeat) {
                if (QDateTime().currentDateTime() >= timeOfLastAlarm(alarm, zapNoRepeate.time)) {  // Последний будильник уже сработал
                    // Выключение будильника
                    m_file.seek(zapNoRepeate.num * SIZE_ZAP);
                    alarm.isOn = false;
                    file << alarm;
                }
            }
        }
    }
    m_file.close();
    m_fileOfNoRepeateAlarms.close();
}

QDateTime AlarmModel::timeOfLastAlarm(Zap alarm, QDateTime timeOfCreate)
{
    QDateTime res = timeOfCreate;
qDebug() << timeOfCreate;
    res.setTime(QTime(floor(alarm.time / 100), alarm.time % 100));
    int dayW = timeOfCreate.date().dayOfWeek();
    bool flag = false;      // Флаг сработает при нахождении последнего будильника
    int j;                  // j это через сколько дней сработает будильник
    for (j = 7; (j >= 0) && !flag; j--) {
        int currentDayW = j + dayW;			// рассматриваемый день недели
        if (currentDayW <= 7) {             // ищем на этой неделе
            int day2 = takeRazryad(alarm.week, 8 - currentDayW);	// 8 = 7 + 1
            if (day2 == 3) {
                flag = true;
            }
        } else {                            // ищем на следующей неделе
            currentDayW -= 7;
            int day2 = takeRazryad(alarm.week, 8 - currentDayW);
            if (day2 == 3) {
                if (j != 7 || timeOfCreate.time() > res.time()) {   // Будильник сработает не в день создания
                    flag = true;
                }
            }
        }
    }
    return res.addDays(j + 1);      // +1 т.к. j в канце цикла уменьшится на 1
}

void AlarmModel::setZapNoRepeate(const int num, const ZapNoRepeate &zap)
{
    m_fileOfNoRepeateAlarms.open(QFile::ReadWrite);
    if (m_fileOfNoRepeateAlarms.exists()) {
        QDataStream f(&m_fileOfNoRepeateAlarms);
        ZapNoRepeate currentZap;
        bool flag = false;          // Флаг сработает при находке
        while (!m_fileOfNoRepeateAlarms.atEnd() && !flag) {
            int pos = m_fileOfNoRepeateAlarms.pos();
            f >> currentZap;
            if (currentZap.num == num) {
                m_fileOfNoRepeateAlarms.seek(pos);
                f << zap;
                flag = true;
            }
        }
    }
    m_fileOfNoRepeateAlarms.close();
}

ZapNoRepeate* AlarmModel::findZapNoRepeate(const int num)
{
    ZapNoRepeate *res = NULL;
    m_fileOfNoRepeateAlarms.open(QFile::ReadWrite);
    if (m_fileOfNoRepeateAlarms.exists()) {
        QDataStream f(&m_fileOfNoRepeateAlarms);
        ZapNoRepeate currentZap;
        bool flag = false;          // Флаг сработает при находке
        while (!m_fileOfNoRepeateAlarms.atEnd() && !flag) {
            f >> currentZap;
            if (currentZap.num == num) {
                res = new ZapNoRepeate;
                *res = currentZap;
                flag = true;
            }
        }
    }
    m_fileOfNoRepeateAlarms.close();
    return res;
}

void AlarmModel::deleteZapNoRepeate(const int num)
{
    QFile newFile(QString(S_FILE_NAME_OF_NOREPEATE_ALARMS)+"$");
    m_fileOfNoRepeateAlarms.open(QFile::ReadOnly);
    newFile.open(QFile::WriteOnly);
    if (m_fileOfNoRepeateAlarms.exists() && newFile.exists()) {
        QDataStream in(&m_fileOfNoRepeateAlarms);
        QDataStream out(&newFile);
        ZapNoRepeate zap;
        in >> zap;
        while (!m_fileOfNoRepeateAlarms.atEnd() && zap.num != num) {
            out << zap;
            in >> zap;
        }
        while (!m_fileOfNoRepeateAlarms.atEnd()) {
            in  >> zap;
            out << zap;
        }
    }
    m_fileOfNoRepeateAlarms.close();
    newFile.close();
    if (m_fileOfNoRepeateAlarms.exists() && newFile.exists()) {
        m_fileOfNoRepeateAlarms.remove();
        newFile.rename(S_FILE_NAME_OF_NOREPEATE_ALARMS);
        m_fileOfNoRepeateAlarms.setFileName(S_FILE_NAME_OF_NOREPEATE_ALARMS);
        if (m_fileOfNoRepeateAlarms.size() == 0) m_fileOfNoRepeateAlarms.remove();
    }
}

void AlarmModel::addZapNoRepeate(const ZapNoRepeate &zap)
{
    qDebug() << zap.num << zap.time;
    qDebug() << "До";
    debugFile(2);
    m_fileOfNoRepeateAlarms.open(QFile::Append);
    if (m_fileOfNoRepeateAlarms.exists()) {
        QDataStream out(&m_fileOfNoRepeateAlarms);
        out << zap;
    }
    m_fileOfNoRepeateAlarms.close();
    qDebug() << "После:";
    debugFile(2);
}

void AlarmModel::debugFile(const int file)
{
    switch (file) {
    case 1:
        m_file.open(QFile::ReadOnly);
        if (m_file.exists()) {
            Zap alarm;
            QDataStream in(&m_file);
            for (int i = 0; !m_file.atEnd(); i++) {
                in >> alarm;
                qDebug() << i << alarm.time << alarm.week << alarm.repeat << alarm.open << alarm.isOn;
            }
        } else qDebug() << "m_file не существует";
        m_file.close();
        break;
    case 2:
        m_fileOfNoRepeateAlarms.open(QFile::ReadOnly);
        if (m_fileOfNoRepeateAlarms.exists()) {
            ZapNoRepeate zap;
            QDataStream in(&m_fileOfNoRepeateAlarms);
            for (int i = 0; !m_fileOfNoRepeateAlarms.atEnd(); i++) {
                in >> zap;
                qDebug() << i << zap.num << zap.time;
            }
        } else qDebug() << "m_fileOfNoRepeateAlarms не существует";
        m_fileOfNoRepeateAlarms.close();
        break;
    }
}

QDataStream& operator<<(QDataStream &dataStreame, const Zap &zap)
{
    dataStreame << zap.time;
    dataStreame << zap.week;
    dataStreame << zap.repeat;
    dataStreame << zap.open;
    dataStreame << zap.isOn;
    return dataStreame;
}

QDataStream& operator>>(QDataStream &dataStreame, Zap &zap)
{
    dataStreame >> zap.time;
    dataStreame >> zap.week;
    dataStreame >> zap.repeat;
    dataStreame >> zap.open;
    dataStreame >> zap.isOn;
    return dataStreame;
}

QDataStream& operator<<(QDataStream &dataStreame, const ZapNoRepeate &zap)
{
    dataStreame << zap.num;
    dataStreame << zap.time;
    return dataStreame;
}

QDataStream& operator>>(QDataStream &dataStreame, ZapNoRepeate &zap)
{
    dataStreame >> zap.num;
    dataStreame >> zap.time;
    return dataStreame;
}

AlarmModel::AlarmModel(Jalousi *jalousiDevice, MassageBox *massageBox, QObject *parent) :
    m_jalousi(jalousiDevice), m_massageBox(massageBox), QAbstractListModel(parent)
{
    m_file.setFileName(S_FILE_NAME);
    m_fileOfNoRepeateAlarms.setFileName(S_FILE_NAME_OF_NOREPEATE_ALARMS);
    update();
}

void AlarmModel::add(int time, int week, bool repeat, bool open)
{
    m_file.open(QFile::Append);
    if (m_file.exists()) {
        QDataStream out(&m_file);
        beginInsertRows(QModelIndex(), rowCount(), rowCount());
        out << time << week << repeat << open << true;
        Alarm al(time, week, repeat, open, true);
        m_alarms.append(al);
        ZapNoRepeate zap;
        zap.num = m_alarms.count() - 1;
        zap.time = QDateTime().currentDateTime();
qDebug() << zap.time;
        addZapNoRepeate(zap);
        endInsertRows();
    }
    m_file.close();
    m_jalousi->file();
}

void AlarmModel::remove(int row)
{
    QFile newFile(QString(S_FILE_NAME)+"$");
    m_file.open(QFile::ReadOnly);
    newFile.open(QFile::WriteOnly);
    if (m_file.exists() && newFile.exists()) {
        QDataStream in(&m_file);
        QDataStream out(&newFile);
        Zap alarm;
        beginRemoveRows(QModelIndex(), row, row);
        for (int i = 0; i < row; i++) {
            in  >> alarm;
            out << alarm;
        }
        in >> alarm;
        if (!alarm.repeat) deleteZapNoRepeate(row); // Если будильник неповторяющийся то удалить
        int i = row + 1;
        while (!m_file.atEnd()) {
            in  >> alarm;
            out << alarm;
            if (!alarm.repeat) {
                // Изменение записи неповторяющиеся будильника
                ZapNoRepeate *zap = findZapNoRepeate(i);
                if (zap) {
                    setZapNoRepeate(i, *zap);
                    delete zap;
                }
            }
            i++;
        }
        m_alarms.removeAt(row);
        endRemoveRows();
        m_massageBox->emitMassage("Запись удалена");
    }
    m_file.close();
    newFile.close();
    if (m_file.exists() && newFile.exists()) {
        m_file.remove();
        newFile.rename(S_FILE_NAME);
        m_file.setFileName(S_FILE_NAME);
        if (m_file.size() == 0) {
            m_file.remove();
            if (m_fileOfNoRepeateAlarms.exists()) m_fileOfNoRepeateAlarms.remove();
        }
        m_jalousi->file();
    }
}

QVariant AlarmModel::data(const QModelIndex & index, int role) const
{
    if (index.row() < 0 || index.row() > m_alarms.count())
        return QVariant();

    const Alarm &al = m_alarms[index.row()];
    if (role == TimeRole)
        return al.time();
    else if (role == WeekRole)
        return al.week();
    else if (role == RepeatRole)
        return al.repeat();
    else if (role == OpenRole)
        return al.open();
    else if (role == IsOnRole)
        return al.isOn();

    return QVariant();
}

QHash<int, QByteArray> AlarmModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[TimeRole] = "time";
    roles[WeekRole] = "week";
    roles[RepeatRole] = "repeat";
    roles[OpenRole] = "open";
    roles[IsOnRole] = "isOn";
    return roles;
}

bool AlarmModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.row() >= 0 && index.row() <= m_alarms.count()) {
        // определяем соответствие между столбцами и полями структуры
        switch (role) {
        case TimeRole:
            m_alarms[index.row()].setTime(value.toInt());
            break;
        case WeekRole:
            m_alarms[index.row()].setWeek(value.toInt());
            break;
        case RepeatRole:
            m_alarms[index.row()].setRepeat(value.toBool());
            break;
        case OpenRole:
            m_alarms[index.row()].setOpen(value.toBool());
            break;
        case IsOnRole:
            m_alarms[index.row()].setIsOn(value.toBool());
            break;
        default:
            return false;
        }
        setZap(index.row(), value, role);
        emit(dataChanged(index, index));
        return true;
    }
    return false;
}


void Alarm::setTime(const int &time)
{
    if (time != m_time) {
        m_time = time;
    }
}

void Alarm::setWeek(const int &week)
{
    if (week != m_week) {
        m_week = week;
    }
}

void Alarm::setRepeat(const bool &repeat)
{
    if (repeat != m_repeat) {
        m_repeat = repeat;
    }
}

void Alarm::setOpen(const bool &open)
{
    if (open != m_open) {
        m_open = open;
    }
}

void Alarm::setIsOn(const bool &isOn)
{
    if (isOn != m_isOn) {
        m_isOn = isOn;
    }
}
