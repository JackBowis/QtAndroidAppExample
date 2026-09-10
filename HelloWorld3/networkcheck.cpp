#include "networkcheck.h"

networkcheck::networkcheck() {
    networkManager = new QNetworkAccessManager(this);
    connect(networkManager, &QNetworkAccessManager::finished, this, &networkcheck::handleNetworkReply);
    qWarning() << "ATTN: Device supports OpenSSL: " << QSslSocket::supportsSsl();
}


void networkcheck::getSourceCode(const QString& url){
    QUrl qUrl(url);
    if (qUrl.isValid()) {
        qWarning() << "ATTN: Initializing Network Request:" << url;
        networkManager->get(QNetworkRequest(qUrl));
    } else {
        qWarning() << "ATTN: Invalid URL:" << url;
    }
}

void networkcheck::handleNetworkReply(QNetworkReply* reply){
    if (reply->error() == QNetworkReply::NoError) {
        QString sourceCode = QString::fromUtf8(reply->readAll());
        mostRecentSourceCode = sourceCode;

        QString versionSnippet = mostRecentSourceCode;
        int indexOfVersion = versionSnippet.lastIndexOf("CANParse Current Version");
        versionSnippet.remove(0, indexOfVersion);
        versionSnippet.chop(versionSnippet.length() - 50); // Should end with something like "CANParse Current Version: 0.0.1</h1></div></div></"
        versionSnippet = versionSnippet.split("<").first(); // Should end with something like "CANParse Current Version: 0.0.1"
        QString versionNumber = versionSnippet.split(" ").last(); // Should end with something like "0.0.1"

        // qWarning() << "ATTN: Source code Version Snippet:" << versionSnippet;
        qWarning() << "ATTN: According to bowisengineering.com, Current Version of CAN-Parse is:" << versionNumber;
        // qWarning() << "ATTN: Source code:" << sourceCode;
    } else {
        qWarning() << "ATTN: Error:" << reply->errorString();
    }
    reply->deleteLater();
}
