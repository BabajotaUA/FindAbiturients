#include "datasource.h"
#include <QDebug>

DataSource::DataSource(QUrl sourceURL, QObject *parent) :
    QObject(parent)
{
    sourceData = "";
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
    sourceData.append(reply->readAll());
}

void DataSource::replyError()
{
    sourceData.append(reply->errorString());
}
