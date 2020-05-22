#include "myt.h"
#include "mainwindow.h"
#include <QJsonObject>
#include <QJsonDocument>

void MYTApp::getSearch(QString query)
{
    QUrl url = QUrl("http://youtube-scrape.herokuapp.com/api/search?q=" + query + "&page=1");

    handler.getResponse(url);   // Will save the results of the given query on raw_results

    QFile rawResults("raw_results.json");
    rawResults.open(QIODevice::ReadOnly | QIODevice::Text);
    QByteArray inputData = rawResults.readAll();

    QJsonDocument resultsDoc = QJsonDocument::fromJson(inputData);
    QJsonObject   results    = resultsDoc.object();

    rawResults.close();
}
