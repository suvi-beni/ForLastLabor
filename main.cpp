#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <communicationmanager.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    CommunicationManager manager;
    manager.DownloadFood();

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
