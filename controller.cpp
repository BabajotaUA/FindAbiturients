#include "controller.h"
#include <QDebug>

Controller::Controller(QObject *parent) :
    QObject(parent)
{
}

void Controller::addNewSource(const QString &source)
{
    model.addNewSource(source);
}

/*QString Controller::showHtmlOutput(int id) const
{
    return QString::fromLocal8Bit(sourceList[id]->getSourceData().data());
}*/


DataModel* Controller::getModel()
{
    return &model;
}


QString Controller::showCoincidenceCount() const
{
    return model.getCoincidenceCount();
}
