#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "alarm.h"
#include "jalousi.h"
#include "massagebox.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;

    QQmlContext *item = engine.rootContext();
    MassageBox *massageBox = new MassageBox;
    Jalousi *jalousiDevice = new Jalousi(massageBox);
    AlarmModel *alarmModel = new AlarmModel(jalousiDevice, massageBox);
    item->setContextProperty("cppMassageBox", massageBox);
    item->setContextProperty("AlarmModel", alarmModel);
    item->setContextProperty("JalousiDevice", jalousiDevice);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
