#ifndef MYT_H
#define MYT_H

#include "nethandler.h"
#include <QString>

class videoData                  // TODO: use struct ?
{
public:
    QString title;
    QString channel;
    QString views;
    QString uploadDate;
    QString videoUrl;
    QString thumbnailUrl;
};

class MYTApp
{
public:
    QList<videoData>  searchResults;
    void              getSearch(QString);
private:
    NetHandler        handler;
};

#endif // MYT_H
