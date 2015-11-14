#ifndef JALOUSI_H
#define JALOUSI_H

#include <QObject>
#include <QBluetoothLocalDevice>
#include "androidrfcomm.h"
#include "massagebox.h"
#include "settings.h"

struct AlarmsZap {
    short time;
    int week;
    bool repeat;
    bool open;
};

class Jalousi : public QObject
{
    Q_OBJECT

    AndroidRfComm m_bluetooth;
    QBluetoothLocalDevice m_localDevice;
    MassageBox *m_massageBox;

public:
    Jalousi(MassageBox *massageBox);

public slots:
    void discover();
    void up(char num);
    void down(char num);
    void stop(char num);
    void time();
    void file();
};

#endif // JALOUSI_H
