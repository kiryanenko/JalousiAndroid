#include "bluetooth.h"
#include <QDebug>

Bluetooth::Bluetooth()
{
    m_localDevice.powerOn();
    //m_localDevice.setHostMode(QBluetoothLocalDevice::HostDiscoverable);
    m_discoveryAgent = new QBluetoothDeviceDiscoveryAgent(this);
    m_socket = NULL;
    //connect(m_discoveryAgent, SIGNAL(finished()), this, SLOT(deviceDiscoverFinished()));
    connect(m_discoveryAgent, SIGNAL(error(QBluetoothDeviceDiscoveryAgent::Error)),
            this, SLOT(error(QBluetoothDeviceDiscoveryAgent::Error)));
    connect(m_discoveryAgent, SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)),
            this, SLOT(deviceDiscovered(QBluetoothDeviceInfo)));
    m_discoveryAgent->setInquiryType(QBluetoothDeviceDiscoveryAgent::GeneralUnlimitedInquiry);
    discover();
}

void Bluetooth::discover()
{
    qDebug() << "Bluetooth discover isActive: " << m_discoveryAgent->isActive();
    m_localDevice.powerOn();
    //m_localDevice.setHostMode(QBluetoothLocalDevice::HostDiscoverable);
    m_discoveryAgent->stop();
    m_discoveryAgent->start();
    qDebug() << "Bluetooth discover start";
    qDebug() << "Bluetooth discover error: " << m_discoveryAgent->error();
}

bool Bluetooth::write(char &byte)
{
    if(m_socket) {
        m_socket->write(&byte);
        return 1;
    } else {
        return 0;
    }
}

bool Bluetooth::write(QByteArray byte)
{
    if(m_socket) {
        m_socket->write(byte);
        return 1;
    } else {
        return 0;
    }
}

//void Bluetooth::deviceDiscoverFinished()
//{
//    qDebug() << "discover finish";
//    if (m_socket) {
//        delete m_socket;
//        m_socket = NULL;
//    }
//    QList<QBluetoothDeviceInfo> listOfDevices = m_discoveryAgent->discoveredDevices();
//    bool flag = false;
//    for (int i = 0; i < listOfDevices.size() && !flag; i++) {
//        qDebug() << "Bluetooth " << listOfDevices[i].name();
//        if(listOfDevices[i].name() == S_BLUETOOTH_NAME) {
//            qDebug() << "Подключение";
//            m_socket = new QBluetoothSocket(QBluetoothServiceInfo::RfcommProtocol);
//            m_socket->connectToService(listOfDevices[i].address(), QBluetoothUuid(QBluetoothUuid::SerialPort),
//                                       QIODevice::WriteOnly);
//            if (m_socket->ConnectingState) qDebug() << "Подключилось";
//            else qDebug() << "Не подключилось!";
//            //m_socket->open(QIODevice::WriteOnly);
//            flag = true;
//        }
//    }
//}

void Bluetooth::deviceDiscovered(QBluetoothDeviceInfo info)
{
    qDebug() << "Bluetooth " << info.name();
    if(info.name() == S_BLUETOOTH_NAME) {
        if (m_socket) {
            delete m_socket;
            m_socket = NULL;
        }
        qDebug() << "Подключение";
        m_socket = new QBluetoothSocket(QBluetoothServiceInfo::RfcommProtocol);
        m_socket->connectToService(info.address(), QBluetoothUuid(QStringLiteral("00001101-0000-1000-8000-00805F9B34FB")));
        if (m_socket->ConnectingState) qDebug() << "Подключилось";
        else qDebug() << "Не подключилось!";
        m_socket->open(QIODevice::WriteOnly);
        m_discoveryAgent->stop();
    }
}

void Bluetooth::error(QBluetoothDeviceDiscoveryAgent::Error err)
{
    qDebug() << "discover error: " << err;
}
