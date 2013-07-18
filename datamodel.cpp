#include "datamodel.h"
#include <QDebug>

DataModel::DataModel(QObject *parent) :
    QAbstractItemModel(parent)
{
    qDebug() << "DataModel CREATED";
    rows = 0;
    columns = 5;
    dataItems = QList<DataParser*>();
}

QModelIndex DataModel::index(int row, int column, const QModelIndex &parent) const
{
    return createIndex(row, column);
}

QModelIndex DataModel::parent(const QModelIndex &child) const
{
    return QModelIndex();
}

int DataModel::rowCount(const QModelIndex &parent) const
{
    return rows;
}

int DataModel::columnCount(const QModelIndex &parent) const
{
    return columns;
}

QVariant DataModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        return QString("OLOLO") + QString::number(index.row());
    }
    return QVariant();
}

QVariant DataModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        switch (section) {
        case 0:
            return "one";
        case 1:
            return "one";
        case 2:
            return "one";
        case 3:
            return "one";
        default:
            return "default";
        }
    }

    return QVariant();
}

void DataModel::addNewSource(const QString &source)
{
    dataItems.append(new DataParser(source, this));
    //emit dataChanged(createIndex(0,0), createIndex(rows, columns));
}

void DataModel::parseDataSource()
{
    foreach (DataParser* item, dataItems) {
        item->parseDataSource();
    }
}

QString DataModel::getCoincidenceCount() const
{
    return dataItems[0]->getSourceTitle();
}
