#include "serialconnector.h"

SerialConnector::SerialConnector() : QObject(NULL)
{

}

SerialConnector::SerialConnector(
    QString portName,
    qint32 baudRate,
    QSerialPort::DataBits dataBits,
    QSerialPort::Parity parity,
    QSerialPort::StopBits stopBits)
    : Communication()
{
    soros_port.setPortName(portName);
    soros_port.setBaudRate(baudRate);
    soros_port.setDataBits(dataBits);
    soros_port.setParity(parity);
    soros_port.setStopBits(stopBits);

    soros_port.setFlowControl(QSerialPort::NoFlowControl);

    QObject::connect(&soros_port,
        SIGNAL(error(QSerialPort::SerialPortError)),
        this, SLOT(handleError(QSerialPort::SerialPortError)));
}
