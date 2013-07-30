#include "datamodel.h"
#include <QDebug>

DataModel::DataModel(QObject *parent) :
    QAbstractItemModel(parent)
{
    qDebug() << "DataModel CREATED" << "attached to:" << parent;
    rows = 0;
    columns = 1;
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
        if (section == 0)
            return "Імя";
        return "Something "+section;//dataItems[section - 1]->getSourceTitle();
    }

    return QVariant();
}

void DataModel::addNewSource(const QString &source)
{
    beginInsertColumns(QModelIndex(),columns,columns);
    dataSources.append(new DataSource(source, this));
    columns++;
    //emit dataChanged(createIndex(0,0), createIndex(rows, columns));
    endInsertColumns();

    beginInsertRows(QModelIndex(),rows,rows+10);
    rows += 10;
    endInsertRows();
}

void DataModel::parseDataSource()
{
    foreach (DataSource* item, dataSources) {
        universities.append(parser.parseDataSource(item));
    }
}

QString DataModel::getCoincidenceCount() const
{
    return "";//dataItems[0]->getSourceTitle();
}
