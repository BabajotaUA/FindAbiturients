#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "datasource.h"
#include <QtCore/QSharedPointer>
#include <QObject>

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = 0);
    virtual ~Controller() {}

    void addNewSource(QString source);
    QString showHtmlOutput(int id) const;

private:
    QList<DataSource*> sourceList;
};

#endif // CONTROLLER_H
