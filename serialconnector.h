#ifndef SERIALCONNECTOR_H
#define SERIALCONNECTOR_H

#include <QObject>
#include <QtSerialPort/QSerialPort>

class SerialConnector : public QObject
{
    Q_OBJECT
    QSerialPort soros_port;

public:
    explicit SerialConnector();

    SerialConnector(QString portName,
               qint32 baudRate,
               QSerialPort::DataBits dataBits,
               QSerialPort::Parity parity,
               QSerialPort::StopBits stopBits);

signals:

public slots:
};

#endif // SERIALCONNECTOR_H
