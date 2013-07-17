#ifndef DATAMODEL_H
#define DATAMODEL_H

#include <QAbstractItemModel>

class DataModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    explicit DataModel(QObject *parent = nullptr);
    virtual ~DataModel() {}
    
    virtual QModelIndex index(int row, int column, const QModelIndex &parent) const;
    virtual QModelIndex parent(const QModelIndex &child) const;
    virtual int rowCount(const QModelIndex &parent) const;
    virtual int columnCount(const QModelIndex &parent) const;
    virtual QVariant data(const QModelIndex &index, int role) const;
    virtual QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    void addNewSource(const QString &source);
    QString getCoincidenceCount() const;
};

#endif // DATAMODEL_H
