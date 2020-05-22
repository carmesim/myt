#ifndef MYT_H
#define MYT_H

#include <QString>
#include <QList>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>

class videoData                  // TODO: use struct ?
{
    QString title;
    QString channel;
    QString views;
    QString uploadDate;
    QString videoUrl;
    QString thumbnailUrl;
};

class NetHandler : public QObject
{
    Q_OBJECT
    QNetworkAccessManager * manager;
private slots:
    void saveResults(QNetworkReply *);
public:
    void getResponse(QUrl url);
};

class MYTApp
{
public:
    QList<videoData>    searchResults;
    void                getSearch(QString);
private:
    NetHandler          handler;
};

#endif // MYT_H
