#include "myt.h"
#include "mainwindow.h"
#include <QObject>
#include <QNetworkRequest>

void NetHandler::replyFinished(QNetworkReply *reply)
{
    qDebug() << reply->readAll();
}

void NetHandler::checkSite(QUrl url)
{
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
    manager->get(QNetworkRequest(url));
}

void MYTApp::getSearch(QString query)
{
    QUrl url = QUrl("http://youtube-scrape.herokuapp.com/api/search?q=" + query + "&page=1");

    handler.checkSite(url);
}
