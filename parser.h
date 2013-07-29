#ifndef DATAPARSER_H
#define DATAPARSER_H

#include "abiturient.h"
#include "datasource.h"
#include <QObject>

class Parser : public QObject
{
    Q_OBJECT
public:
    explicit Parser(QObject *parent = nullptr);
    virtual ~Parser() {qDebug() << "Parser DELETED";}

    QString getSourceTitle() const;
    void parseDataSource(DataSource* suorce);

private:
    QString sourceTitle;
    QList<Abiturient*> abiturients;

    void parseTableRows(int begin, int end, const QString &tableData);
    void setAbiturients(const QString &rowData);
    QStringList parseTableColumns(const QString &rowData);
};

#endif // DATAPARSER_H
