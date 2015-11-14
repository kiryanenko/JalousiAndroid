#ifndef MASSAGEBOX_H
#define MASSAGEBOX_H

#include <QObject>
#include <QString>

class MassageBox : public QObject
{
    Q_OBJECT
public:
    explicit MassageBox(QObject *parent = 0);
    void emitMassage(QString msg) { emit massage(msg); }

signals:
    void massage(QString value);
};

#endif // MASSAGEBOX_H
