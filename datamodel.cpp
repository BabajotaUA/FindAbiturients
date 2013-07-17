#include "datamodel.h"

DataModel::DataModel(QObject *parent) :
    QAbstractItemModel(parent)
{

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
    return 5;
}

int DataModel::columnCount(const QModelIndex &parent) const
{
    return parent.column();
}

QVariant DataModel::data(const QModelIndex &index, int role) const
{
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
}

void DataModel::addNewSource(const QString &source)
{

}

QString DataModel::getCoincidenceCount() const
{
    return "jdfhsjkdfhsjkdf";
}
