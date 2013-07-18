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
    auto tableStart = preparedData.indexOf("<tbody>");
    auto tableEnd = preparedData.indexOf("<thead><tr>", tableStart);
    QString preparedTableData = preparedData.midRef(tableStart).toString();
    parseTableRows(0, (tableEnd - tableStart) - 6, preparedTableData);
}

void DataParser::parseTableRows(int begin, int end, const QString &tableData)
{
    auto rowStart = tableData.indexOf("<tr>",begin);
    auto rowEnd = tableData.indexOf("</tr>",rowStart);

    if (rowEnd > end || rowStart == -1 || rowEnd == -1)
        return;

    QString preparedRow = tableData.mid(rowStart, rowEnd - rowStart);
    setAbiturients(preparedRow);
    parseTableRows(rowEnd, end, tableData);
}

void DataParser::setAbiturients(const QString &rowData)
{
    QList<QString> tmp;
    int offset = 0;
    for (int i = 0; i < 12; ++i) {
        tmp.append(parseTableColumns(offset, rowData));
        offset += tmp[i].length() + 9;
    }

    Abiturient* abiturient = new Abiturient(this);
    abiturient->setId(tmp[0].toInt());
    abiturient->setName(tmp[1]);
    if (tmp[9] == "&#43;")
        abiturient->setFlagOutOfCompetition(true);
    if (tmp[10] == "&#43;")
        abiturient->setFlagFirstOfAll(true);
    if (tmp[11] == "&#43;")
        abiturient->setFlagOriginalAtestat(true);
    abiturients.append(abiturient);
    qDebug() << abiturient->getId()
             << abiturient->getNmae()
             << abiturient->getPointsTotal()
             << abiturient->getFlagOutOfCompetition()
             << abiturient->getFlagFirstOfAll()
             << abiturient->getFlagOriginalAtestat();
}

QString DataParser::parseTableColumns(int begin, const QString &tableData)
{
    auto columnStart = tableData.indexOf("<td>",begin) + 4;
    auto columnEnd = tableData.indexOf("</td>",columnStart);

    return tableData.mid(columnStart, columnEnd - columnStart);
}
