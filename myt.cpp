#include "myt.h"
#include "mainwindow.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QDebug>

void MYTApp::getSearch(QString query)
{
    QUrl url = QUrl("http://youtube-scrape.herokuapp.com/api/search?q=" + query + "&page=1");

    handler.getResponse(url);   // Will save the results of the given query on raw_results

    QFile rawResults("raw_results.json");
    rawResults.open(QIODevice::ReadOnly | QIODevice::Text);
    QByteArray    inputData = rawResults.readAll();
    QJsonObject   results   = QJsonDocument::fromJson(inputData).object();

    if (results.isEmpty())
        qDebug() << "Problem reading query JSON.\n";

    QTextStream stream(stdout);
    stream << "Lendo vídeos\n";
    foreach(QJsonValue element, results["results"].toArray())
    {
        QJsonObject node = element.toObject();

        videoData vid;
        vid.title        = static_cast<QJsonValue>(node["video"])["title"].toString();
        vid.views        = static_cast<QJsonValue>(node["video"])["views"].toString();
        vid.channel      = static_cast<QJsonValue>(node["uploader"])["username"].toString();
        vid.videoUrl     = static_cast<QJsonValue>(node["video"])["url"].toString();
        vid.thumbnailUrl = static_cast<QJsonValue>(node["video"])["thumbnail_src"].toString();
        vid.uploadDate   = static_cast<QJsonValue>(node["video"])["upload_date"].toString();

//        stream << vid.title << '\n';
//        stream << vid.views << '\n';
//        stream << vid.channel << '\n';
//        stream << vid.videoUrl << '\n';
//        stream << vid.thumbnailUrl << '\n';
//        stream << vid.uploadDate << '\n';
        searchResults.append(vid);

    }

    rawResults.close();
}
