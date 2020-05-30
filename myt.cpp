#include "myt.h"
#include "mainwindow.h"
#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QNetworkReply>

MYTApp::MYTApp()
{
    connect(&manager, &QNetworkAccessManager::finished, this, &MYTApp::responseReceived);
}

void MYTApp::getSearch(QString query, int page)
{
    QUrl url = QUrl("http://youtube-scrape.herokuapp.com/api/search?q=" + query + "&page=" + QString::number(page));

    manager.get(QNetworkRequest(url));
}

void MYTApp::responseReceived(QNetworkReply *reply)
{
    searchResults.clear();
    QJsonObject results = QJsonDocument::fromJson(reply->readAll()).object();

    for(QJsonValue element : results["results"].toArray())
    {
        QJsonObject node = element.toObject();
        QJsonValue video = node["video"];
        QJsonValue uploader = node["uploader"];

        videoData vid;

        vid.title.setText(video["title"].toString());
        vid.views.setText(video["views"].toString());
        vid.channel.setText(uploader["username"].toString());
        vid.videoUrl.setText(video["url"].toString());
        vid.thumbnail.setData(Qt::DecorationRole, thumbGrab.fetchThumbnail(video["thumbnail_src"].toString()).scaledToWidth(150, Qt::SmoothTransformation));
        vid.uploadDate.setText(video["upload_date"].toString());

        searchResults.append(vid);
    }

    emit searchFinished(searchResults);
}
