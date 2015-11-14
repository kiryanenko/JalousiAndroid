#ifndef DATA
#define DATA

#include <QAbstractListModel>
#include <QString>
#include <QDataStream>
#include <QFile>
#include <QVariant>
#include <QDateTime>
#include <math.h>
#include "settings.h"
#include "jalousi.h"
#include "massagebox.h"

class Alarm;
class AlarmModel;

// Структура записи будильника
struct Zap {
    int time;
    int week;
    bool repeat;
    bool open;
    bool isOn;
};
const int SIZE_ZAP = 2 * sizeof(int) + 3 * sizeof(bool);        // размер 1 записи
// Структура для файла содержащего даты создания неповторяющихся будильников
struct ZapNoRepeate {
    int num;            // Номер записи в файле с будильниками
    QDateTime time;
};

QDataStream& operator<<(QDataStream &dataStreame, const Zap &zap);
QDataStream& operator>>(QDataStream &dataStreame, Zap &zap);
QDataStream& operator<<(QDataStream &dataStreame, const ZapNoRepeate &zap);
QDataStream& operator>>(QDataStream &dataStreame, ZapNoRepeate &zap);

class Alarm
{
    int m_time;
    int m_week;
    bool m_repeat;
    bool m_open;
    bool m_isOn;

public:
    Alarm(const int &time, const int &week, const bool &repeat,
               const bool &open, const bool &isOn, QObject *parent=0) :
        m_time(time), m_week(week), m_repeat(repeat),
        m_open(open), m_isOn(isOn) {}

    int time() const { return m_time; }
    void setTime(const int &time);

    int week() const { return m_week; }
    void setWeek(const int &week);

    bool repeat() const { return m_repeat; }
    void setRepeat(const bool &repeat);

    bool open() const { return m_open; }
    void setOpen(const bool &open);

    bool isOn() const { return m_isOn; }
    void setIsOn(const bool &isOn);
};

class AlarmModel : public QAbstractListModel
{
    Q_OBJECT

    QFile m_file;                   // Файл бадильников
    QFile m_fileOfNoRepeateAlarms;  // Файл содержащий даты создания неповторяющихся будильников
    QList<Alarm> m_alarms;
    Jalousi *m_jalousi;
    MassageBox *m_massageBox;

    void update();
    void setZap(int num, const QVariant &value, int role);
    // Функция выключающая непеовторяющиеся будильники
    void noRepeateOff();
    // Функция возвращает время последнего будильника
    QDateTime timeOfLastAlarm(Zap alarm, QDateTime timeOfCreate);
    // Функция отделяющая разрад от числа
    int takeRazryad(long num, int i) { return floor((num % (int)pow(10, i)) / pow(10, i - 1)); }
    // Функция изменяющая запись в непеовторяющихся будильниках
    void setZapNoRepeate(const int num, const ZapNoRepeate &zap);
    // Функция поиска записи в непеовторяющихся будильниках
    ZapNoRepeate* findZapNoRepeate(const int num);
    // Функция удаляющая запись в непеовторяющихся будильниках
    void deleteZapNoRepeate(const int num);
    // Функция добавляющая запись в непеовторяющиеся будильники
    void addZapNoRepeate(const ZapNoRepeate &zap);
    // Функция выводящая в консоль файл с будильниками 1 - m_file; 2 - m_fileOfNoRepeateAlarms
    void debugFile(const int file = 1);

public:
    AlarmModel(Jalousi *jalousiDevice, MassageBox *massageBox, QObject *parent = 0);
    int rowCount(const QModelIndex & parent = QModelIndex()) const { m_alarms.count(); }
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
    QHash<int, QByteArray> roleNames() const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);

    enum alarmRoles { // множество возможных значений поля
        TimeRole = Qt::DisplayRole,
        WeekRole = Qt::UserRole + 1,
        RepeatRole = Qt::UserRole + 2,
        OpenRole = Qt::UserRole + 3,
        IsOnRole = Qt::UserRole + 4
    };

public slots:
    void add(int time, int week, bool repeat, bool open);
    void remove(int row);

    int r_time() const { return TimeRole; }            // роли
    int r_week() const { return WeekRole; }
    int r_repeat() const { return RepeatRole; }
    int r_open() const { return OpenRole; }
    int r_isOn() const { return IsOnRole; }

};

#endif // DATA

