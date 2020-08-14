#ifndef THUMBNAILGRABBER_H
#define THUMBNAILGRABBER_H

#include <QEventLoop>
#include <QImage>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class ThumbnailGrabber : public QObject
{
    Q_OBJECT

public:
    ThumbnailGrabber();
    QImage fetchThumbnail(QUrl thumbnailUrl);

private slots:
    /*!
     * \brief Slot for receiving the thumbnail data from QNetworkAccessManager.
     * \param reply Reply containing the thumbnail.
     */
    void replyReceived(QNetworkReply *reply);

private:
    /*!
     * \brief Loop for waiting while the thumbnail is fetched.
     */
    QEventLoop waitLoop;

    /*!
     * \brief Variable that holds the fetched thumbnail.
     */
    QImage fetchedThumbnail;

    /*!
     * \brief QNetworkAccessManager for fetching thumbnails.
     */
    QNetworkAccessManager manager;
};

#endif // THUMBNAILGRABBER_H
