#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "datamodel.h"
#include <QObject>

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = 0);
    virtual ~Controller() {}

    void addNewSource(const QString &source);
    QString showCoincidenceCount() const;
    DataModel *getModel();
    //QString showHtmlOutput(int id) const;

private:
    DataModel model;
};

#endif // CONTROLLER_H
