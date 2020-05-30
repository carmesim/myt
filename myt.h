#ifndef MYT_H
#define MYT_H

#include <QImage>
#include <QNetworkAccessManager>
#include <QObject>
#include <QString>
#include <QTableWidgetItem>
#include "thumbnailgrabber.h"

class videoData
{
public:
    QTableWidgetItem thumbnail;
    QTableWidgetItem channel;
    QTableWidgetItem title;
    QTableWidgetItem uploadDate;
    QTableWidgetItem videoUrl;
    QTableWidgetItem views;
};

class MYTApp : public QObject
{
    Q_OBJECT

public:
    MYTApp();
    QList<videoData> searchResults;
    /*!
     * \brief Requests a video search whose results are returned via the searchFinished signal.
     * \param query Search string.
     * \param page What page to look for. Set to the first page by default.
     */
    void getSearch(QString query, int page = 1);
private slots:
    /*!
     * \brief Slot for receiving the NetHandler object's response.
     * \param response QByteArray containing the HTTP response obtained by the NetHandler object.
     */
    void responseReceived(QNetworkReply *reply);
private:
    /*!
     * \brief QNetworkManager object for making search requests.
     */
    QNetworkAccessManager manager;

    /*!
     * \brief ThumbnailGrabber object for retrieving video thumbnails.
     */
    ThumbnailGrabber thumbGrab;
signals:
    /*!
     * \brief Signals that the search is finished and returns the list of found videos.
     * \param videoList List of found videos.
     */
    void searchFinished(QList<videoData> videoList);
};

#endif // MYT_H
