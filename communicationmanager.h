#ifndef COMMUNICATIONMANAGER_H
#define COMMUNICATIONMANAGER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrlQuery>
#include <QByteArray>

class CommunicationManager : public QObject
{
    Q_OBJECT
    QNetworkAccessManager network;
    QNetworkReply* reply;
    QByteArray received;
    static const QString host;
    static const int port;

public:
    explicit CommunicationManager();
    void DownloadFood();


signals:

public slots:
    void finishedDownload();
};

#endif // COMMUNICATIONMANAGER_H
