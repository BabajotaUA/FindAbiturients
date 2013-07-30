#include "university.h"

University::University(const QString &uName, QObject *parent) :
    QObject(parent)
{
    universityName = uName;
}

void University::addAbiturient()
{
}


QList<Abiturient *> *University::getAbiturientList()
{
    return &abiturients;
}
