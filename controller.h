#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "datamodel.h"
#include <QObject>

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = 0);
    virtual ~Controller() {qDebug() << "Controller DELETED";}

    void addNewSource(const QString &source);
    void showResults();
    QString showCoincidenceCount() const;
    DataModel* getModel();

private:
    DataModel model;
};

#endif // CONTROLLER_H
