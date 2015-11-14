#include "jalousi.h"

#include <QDateTime>
#include <QFile>
#include <QDataStream>
#include <QDebug>

Jalousi::Jalousi(MassageBox *massageBox): m_massageBox(massageBox)
{
    discover();
}

void Jalousi::discover()
{
    m_localDevice.powerOn();
    if(m_bluetooth.isEnabled()) {
        m_bluetooth.connect(QString(S_BLUETOOTH_NAME));
        if (m_bluetooth.isConnected()) {
            qDebug() << "Подключилось";
            m_massageBox->emitMassage("Подключилось");
            time();
            file();
        } else {
            qDebug() << "Не подключилось";
            m_massageBox->emitMassage("Не подключилось");
        }
    } else {
        qDebug() << "Блютуз адаптера не обнаружен";
        m_massageBox->emitMassage("Блютуз адаптера не обнаружен");
    }
}

void Jalousi::up(char num)
{
    if (m_bluetooth.isConnected()) {
        char fun = 'u';
        m_bluetooth.send(QByteArray(&fun, sizeof fun));
        m_bluetooth.send(QByteArray(&num, sizeof num));
    } else m_massageBox->emitMassage("Жалюзи не подключены");
}

void Jalousi::down(char num)
{
    if (m_bluetooth.isConnected()) {
        char fun = 'd';
        m_bluetooth.send(QByteArray(&fun, sizeof fun));
        m_bluetooth.send(QByteArray(&num, sizeof num));
    } else m_massageBox->emitMassage("Жалюзи не подключены");
}

void Jalousi::stop(char num)
{
    if (m_bluetooth.isConnected()) {
        char fun = 's';
        m_bluetooth.send(QByteArray(&fun, sizeof fun));
        m_bluetooth.send(QByteArray(&num, sizeof num));
    }
}

void Jalousi::time()
{
    if (m_bluetooth.isConnected()) {
        QDateTime time;
        char fun = 't';
        m_bluetooth.send(QByteArray(&fun, sizeof fun));
        char byte = time.currentDateTime().time().hour();
        m_bluetooth.send(QByteArray(&byte, sizeof byte));
        byte = time.currentDateTime().time().minute();
        m_bluetooth.send(QByteArray(&byte, sizeof byte));
        byte = time.currentDateTime().date().day();
        m_bluetooth.send(QByteArray(&byte, sizeof byte));
        byte = time.currentDateTime().date().month();
        m_bluetooth.send(QByteArray(&byte, sizeof byte));
        byte = time.currentDateTime().date().year() - 2000;
        m_bluetooth.send(QByteArray(&byte, sizeof byte));
    }
}

void Jalousi::file()
{
    if (m_bluetooth.isConnected()) {
        QFile f(S_FILE_NAME);
        int time, week;
        bool repeat, open, isOn;
        AlarmsZap zap;
        QList <AlarmsZap> list;
        QDataStream in(&f);
        f.open(QFile::ReadOnly);
        while (!f.atEnd()) {
            in  >> time >> week >> repeat >> open >> isOn;
            if (isOn) {
                zap.time = time;
                zap.week = week;
                zap.repeat = repeat;
                zap.open = open;
                list.append(zap);
            }
        }
        f.close();
        char fun = 'f';
        m_bluetooth.send(QByteArray(&fun, sizeof fun));
        char n = list.count();
        m_bluetooth.send(QByteArray(&n, sizeof fun));
        for (int i = 0; i < n; i++) {
            m_bluetooth.send(QByteArray((char *)&list[i].time, sizeof list[i].time));
            m_bluetooth.send(QByteArray((char *)&list[i].week, sizeof list[i].week));
            m_bluetooth.send(QByteArray((char *)&list[i].repeat, sizeof list[i].repeat));
            m_bluetooth.send(QByteArray((char *)&list[i].open, sizeof list[i].open));
        }
        m_massageBox->emitMassage("Файл отправлен");
    } else m_massageBox->emitMassage("Файл не отправился, т.к не подключено к устройству");
}
