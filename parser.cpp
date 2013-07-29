#include "parser.h"
#include <QtCore/QStringList>

Parser::Parser(QObject *parent) :
    QObject(parent)
{
    qDebug() << "DataParser CREATED" << "attached to:" << parent;
}

QString Parser::getSourceTitle() const
{
    return sourceTitle;
}

void Parser::parseDataSource(DataSource *suorce)
{
    QString preparedData = QString::fromLocal8Bit(suorce->getSourceData());
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

void Parser::parseTableRows(int begin, int end, const QString &tableData)
{
    auto rowStart = tableData.indexOf("<tr>",begin) + 4;
    auto rowEnd = tableData.indexOf("</tr>",rowStart);

    if (rowEnd > end || rowStart == -1 || rowEnd == -1)
        return;

    QString preparedRow = tableData.mid(rowStart, rowEnd - rowStart);
    setAbiturients(preparedRow);
    parseTableRows(rowEnd, end, tableData);
}

void Parser::setAbiturients(const QString &rowData)
{
    QStringList columnValue = parseTableColumns(rowData);

    Abiturient* abiturient = new Abiturient(this);
    abiturient->setId(columnValue[0].toInt());
    abiturient->setName(columnValue[1]);
    abiturient->setPointsTotal(columnValue[2].toDouble());
    if (columnValue[9] == "&#43;")
        abiturient->setFlagOutOfCompetition(true);
    if (columnValue[10] == "&#43;")
        abiturient->setFlagFirstOfAll(true);
    if (columnValue[11] == "&#43;")
        abiturient->setFlagOriginalAtestat(true);
    abiturients.append(abiturient);
    qDebug() << abiturient->getId()
             << abiturient->getNmae()
             << abiturient->getPointsTotal()
             << abiturient->getFlagOutOfCompetition()
             << abiturient->getFlagFirstOfAll()
             << abiturient->getFlagOriginalAtestat();
}

QStringList Parser::parseTableColumns(const QString &rowData)
{
    auto columns = rowData.split("<td>", QString::SkipEmptyParts);
    QStringList result;

    foreach (QString val, columns) {
        result.append(val.left(val.length()-5));
    }

    return result;
}
