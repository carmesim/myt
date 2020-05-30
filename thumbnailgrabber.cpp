#include "thumbnailgrabber.h"

ThumbnailGrabber::ThumbnailGrabber()
{
    connect(&manager, &QNetworkAccessManager::finished, this, &ThumbnailGrabber::replyReceived);
    connect(&manager, &QNetworkAccessManager::finished, &waitLoop, &QEventLoop::quit);
}

QImage ThumbnailGrabber::fetchThumbnail(QUrl thumbnailUrl)
{
    manager.get(QNetworkRequest(thumbnailUrl));
    waitLoop.exec();
    return fetchedThumbnail;
}

void ThumbnailGrabber::replyReceived(QNetworkReply *reply)
{
    fetchedThumbnail.loadFromData(reply->readAll());
}
