#include "nethandler.h"

void NetHandler::saveResults(QNetworkReply *reply)
{
    QFile caFile("raw_results.json");
    caFile.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream outStream(&caFile);
    outStream << reply->readAll();
    caFile.close();
}

void NetHandler::getResponse(QUrl url)
{
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(saveResults(QNetworkReply*)));
    manager->get(QNetworkRequest(url));
}
