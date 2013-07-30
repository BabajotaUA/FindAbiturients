#ifndef DATAMODEL_H
#define DATAMODEL_H

#include "datasource.h"
#include "parser.h"
#include "university.h"
#include <QAbstractItemModel>

class DataModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    explicit DataModel(QObject *parent = nullptr);
    virtual ~DataModel() {qDebug() << "DataModel DELETED";}
    
    virtual QModelIndex index(int row, int column, const QModelIndex &parent) const;
    virtual QModelIndex parent(const QModelIndex &child) const;
    virtual int rowCount(const QModelIndex &parent) const;
    virtual int columnCount(const QModelIndex &parent) const;
    virtual QVariant data(const QModelIndex &index, int role) const;
    virtual QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    void addNewSource(const QString &source);
    void parseDataSource();
    QString getCoincidenceCount() const;

private:
    QList<DataSource*> dataSources;
    QList<University*> universities;
    Parser parser;
    int rows, columns;

};

#endif // DATAMODEL_H
