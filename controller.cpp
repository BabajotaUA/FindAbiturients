#include "controller.h"
#include <QDebug>

Controller::Controller(QObject *parent) :
    QObject(parent)
{
}

void Controller::addNewSource(QString source)
{
    sourceList.append(new DataSource(QUrl(source)));
}

QString Controller::showHtmlOutput(int id) const
{
    return QString::fromLocal8Bit(sourceList[id]->getSourceData().data());
}
