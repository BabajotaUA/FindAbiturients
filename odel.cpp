#include "odel.h"

DataModel::DataModel(QObject *parent) :
    QAbstractItemModel(parent)
{
    rows = 4;
    columns = 0;
}

QModelIndex DataModel::index(int row, int column, const QModelIndex &parent) const
{
    return createIndex(row,column);
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
        return QString("VOVO") + index.row();
    else
        return QVariant();
}

QVariant DataModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal)
    {
        if (role == Qt::DisplayRole)
        {
            switch (section) {
            case 0:
                return "ONE";
            case 1:
                return "TWO";
            case 2:
                return "THREE";
            case 3:
                return "FOUR";
            default:
                break;
            }
        }
    }
}

QString DataModel::getCoincidenceCount() const
{
    return QString("sdkfjslkdjfsdklf");
}

void DataModel::addNewSource(const QString &source)
{
    dataSources.append(new DataSource(QUrl(source), this));
}
