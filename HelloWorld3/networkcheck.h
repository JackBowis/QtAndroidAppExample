#ifndef NETWORKCHECK_H
#define NETWORKCHECK_H

#include <QDesktopServices>
#include <QUrl>

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QSslSocket>

class networkcheck : public QObject
{
    Q_OBJECT

public:
    networkcheck();

    QNetworkAccessManager *networkManager;
    QString mostRecentSourceCode = "";

public slots:
    void getSourceCode(const QString& url);
    void handleNetworkReply(QNetworkReply* reply);
};

#endif // NETWORKCHECK_H
