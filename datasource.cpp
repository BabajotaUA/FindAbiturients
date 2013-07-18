#include "datasource.h"

DataSource::DataSource(const QUrl &sourceURL, QObject *parent) :
    QObject(parent)
{
    qDebug() << "DataSource CREATED";
    sourceData = "";
    reply = manager.get(QNetworkRequest(sourceURL));
    connect(reply,SIGNAL(finished()),SLOT(replyFinished()));
    connect(reply,SIGNAL(error(QNetworkReply::NetworkError)),SLOT(replyError()));
}

char *DataSource::getSourceData()
{
    return sourceData.data();
}

void DataSource::replyFinished()
{
    sourceData.append(reply->readAll());
}

void DataSource::replyError()
{
    sourceData.append(reply->errorString());
}
