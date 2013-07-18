#ifndef DATAPARSER_H
#define DATAPARSER_H

#include "datasource.h"
#include "abiturient.h"
#include <QObject>

class DataParser : public QObject
{
    Q_OBJECT
public:
    explicit DataParser(const QString &source, QObject *parent = nullptr);
    virtual ~DataParser() {qDebug() << "DataParser DELETED";}

    QString getSourceTitle() const;
    void parseDataSource();

private:
    QString sourceTitle;
    DataSource* dataSource;
    QList<Abiturient*> abiturients;

    void parseTableRows(int begin, int end, const QString &tableData);
    void setAbiturients(const QString &rowData);
    QString parseTableColumns(int begin, const QString &tableData);
};

#endif // DATAPARSER_H
