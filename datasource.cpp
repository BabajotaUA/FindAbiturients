#include "datasource.h"

DataSource::DataSource(QUrl sourceURL, QObject *parent) :
    QObject(parent)
{
    reply = manager.get(QNetworkRequest(sourceURL));
    connect(reply,SIGNAL(finished()),SLOT(replyFinished()));
    connect(reply,SIGNAL(error(QNetworkReply::NetworkError)),SLOT(replyError()));
}

QByteArray DataSource::getSourceData() const
{
    return sourceData;
}

void DataSource::replyFinished()
{
    sourceData = reply->readAll();
}

void DataSource::replyError()
{
    sourceData += reply->errorString();
}
