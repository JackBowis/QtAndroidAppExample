#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QSslSocket>
#include <QUrl>
#include "networkcheck.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/HelloWorld3/main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);

    qWarning() << "ATTN: Build Version String:" << QSslSocket::sslLibraryBuildVersionString();
    qWarning() << "ATTN: Version String:" << QSslSocket::sslLibraryVersionString();

    networkcheck *myNetworkCheck = new networkcheck();
    myNetworkCheck->getSourceCode("https://bowisengineering.com/versioncheck");

    return app.exec();
}
