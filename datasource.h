#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

class DataSource : public QObject
{
    Q_OBJECT
public:
    explicit DataSource(QUrl sourceURL, QObject *parent = nullptr);
    virtual ~DataSource() {}

    QByteArray getSourceData() const;
    QByteArray sourceData;

signals:
    void replyReceived(QString);
    
private slots:
    void replyFinished();
    void replyError();

private:
    QNetworkAccessManager manager;
    QNetworkReply *reply;
};

#endif // CONNECTOR_H
