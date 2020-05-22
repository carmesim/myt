#ifndef NETHANDLER_H
#define NETHANDLER_H

#include <QList>
#include <QTextStream>
#include <QFile>
#include <QByteArray>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>

class NetHandler : public QObject
{
    Q_OBJECT
    QNetworkAccessManager * manager;
private slots:
    void saveResults(QNetworkReply *);
public:
    void getResponse(QUrl url);
};

#endif // NETHANDLER_H
