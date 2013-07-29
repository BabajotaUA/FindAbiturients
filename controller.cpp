#include "controller.h"

Controller::Controller(QObject *parent) :
    QObject(parent)
{
    qDebug() << "Controller CREATED" << "attached to:" << parent;
}

void Controller::addNewSource(const QString &source)
{
    model.addNewSource(source);
}

void Controller::showResults()
{
    model.parseDataSource();
}

DataModel* Controller::getModel()
{
    return &model;
}

QString Controller::showCoincidenceCount() const
{
    return model.getCoincidenceCount();
}
