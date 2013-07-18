#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QDebug>

class DataSource : public QObject
{
    Q_OBJECT
public:
    explicit DataSource(const QUrl &sourceURL, QObject *parent = nullptr);
    virtual ~DataSource() {qDebug() << "DataSource DELETED";}

    char *getSourceData();

signals:
    void replyReceived(QString);
    
private slots:
    void replyFinished();
    void replyError();

private:
    QNetworkAccessManager manager;
    QNetworkReply *reply;
    QByteArray sourceData;
};

#endif // CONNECTOR_H
