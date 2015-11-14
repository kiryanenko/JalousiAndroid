#ifndef BLUETOOTH_H
#define BLUETOOTH_H

#include <QDeclarativeItem>
#include <QBluetoothLocalDevice>
#include <QBluetoothSocket>
#include <QBluetoothDeviceDiscoveryAgent>
#include "settings.h"

class Bluetooth : public QDeclarativeItem
{
    Q_OBJECT

    QBluetoothLocalDevice m_localDevice;
    QBluetoothSocket *m_socket;
    QBluetoothDeviceDiscoveryAgent *m_discoveryAgent;

public:
    explicit Bluetooth();
    void discover();
    bool write(char &byte);
    bool write(QByteArray byte);

public slots:
    //void deviceDiscoverFinished();
    void deviceDiscovered(QBluetoothDeviceInfo info);
    void error(QBluetoothDeviceDiscoveryAgent::Error err);
};

#endif // BLUETOOTH_H
