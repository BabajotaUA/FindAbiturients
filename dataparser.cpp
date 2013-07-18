#include "dataparser.h"

DataParser::DataParser(const QString &source, QObject *parent) :
    QObject(parent)
{
    qDebug() << "DataParser CREATED";
    dataSource = new DataSource(QUrl(source), this);
    sourceTitle = "Add Link!";
}

QString DataParser::getSourceTitle() const
{
    return sourceTitle;
}

void DataParser::parseDataSource()
{
    QString preparedData = QString::fromLocal8Bit(dataSource->getSourceData());
    if (!preparedData.contains("<title>"))
    {
        sourceTitle = preparedData;
        return;
    }
    auto titleStart = preparedData.indexOf("<title>") + 7;
    auto titleEnd = preparedData.indexOf(" - ", titleStart);
    sourceTitle = preparedData.midRef(titleStart, titleEnd - titleStart).toString();
    auto tableStart = preparedData.indexOf("<tbody>") + 7;
    auto tableEnd = preparedData.indexOf("<thead><tr>", tableStart);
    QString preparedTableData = preparedData.midRef(tableStart, tableEnd - tableStart).toString();
    qDebug() << sourceTitle << preparedTableData;

}
