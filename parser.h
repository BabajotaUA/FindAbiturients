#ifndef DATAPARSER_H
#define DATAPARSER_H

#include "university.h"
#include "datasource.h"
#include <QObject>

class Parser : public QObject
{
    Q_OBJECT
public:
    explicit Parser(QObject *parent = nullptr);
    virtual ~Parser() {qDebug() << "Parser DELETED";}

    University* parseDataSource(DataSource* suorce);

private:
    void parseTableRows(int begin, int end, const QString &tableData);
    void setAbiturients(const QString &rowData);
    QStringList parseTableColumns(const QString &rowData);
};

#endif // DATAPARSER_H
