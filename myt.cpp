#include "myt.h"
#include "mainwindow.h"
#include <QObject>
#include <QNetworkRequest>

void NetHandler::saveResults(QNetworkReply *reply)
{
    qDebug() << reply->readAll();
}

void NetHandler::getResponse(QUrl url)
{
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(saveResults(QNetworkReply*)));
    manager->get(QNetworkRequest(url));
}

void MYTApp::getSearch(QString query)
{
    QUrl url = QUrl("http://youtube-scrape.herokuapp.com/api/search?q=" + query + "&page=1");

    handler.getResponse(url);
}
