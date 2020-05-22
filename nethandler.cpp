#include "nethandler.h"

void NetHandler::saveResults(QNetworkReply *reply)
{
    QFile rawResults("raw_results.json");
    rawResults.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream outStream(&rawResults);
    outStream << reply->readAll();
    rawResults.close();
}

void NetHandler::getResponse(QUrl url)
{
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(saveResults(QNetworkReply*)));
    manager->get(QNetworkRequest(url));
}
