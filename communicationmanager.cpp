#include "communicationmanager.h"

CommunicationManager::CommunicationManager() : QObject(NULL)
{

}

void CommunicationManager::DownloadFood()
{
    qDebug("Starting Downloading Foods");
    QUrl uri;
    QUrlQuery quriquery;
    quriquery.addQueryItem("q", "paprika");
    quriquery.addQueryItem("p", "1");
    quriquery.addQueryItem("s", "1");
    quriquery.addQueryItem("contentType", "application/json");
    uri.setScheme("http");
    uri.setHost(host);
    uri.setPort(port);
    uri.setPath("/getfood.php");
    uri.setQuery(quriquery);
    //qDebug() << uri.url();
    QNetworkRequest request(uri);
    reply = network.get(request);

    connect(reply, SIGNAL(finished()),this,SLOT(finishedDownload()));

}

void CommunicationManager::finishedDownload()
{
    if (reply->error())
    {
        qDebug() << reply->errorString();
    }
    else
    {
        received.clear();
        received.append(reply->readAll());
        qDebug() << received;
    }
}


const int CommunicationManager::port = 80;
const QString CommunicationManager::host= QString("kaloriabazis.hu");
