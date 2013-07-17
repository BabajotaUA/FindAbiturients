#ifndef DATARESULT_H
#define DATARESULT_H

#include "datamodel.h"
#include "datasource.h"
#include <QAbstractItemModel>

class DataModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    explicit DataModel(QObject *parent = nullptr);
    virtual ~DataModel() {}

    QModelIndex index(int row, int column, const QModelIndex &parent) const;
    QModelIndex parent(const QModelIndex &child) const;
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    QString getCoincidenceCount() const;
    void addNewSource(const QString &source);

private:
    QList<DataSource*> dataSources;
    int rows, columns;
};

#endif // DATARESULT_H
