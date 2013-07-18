#include "abiturient.h"

Abiturient::Abiturient(QObject *parent) :
    QObject(parent)
{
    id = 0;
    abiturientNmae = "";
    pointsTotal = 0.0;
    flagOriginalAtestat = false;
    flagOutOfCompetition = false;
    flagFirstOfAll = false;
}

int Abiturient::getId() const
{
    return id;
}

void Abiturient::setId(int value)
{
    id = value;
}

QString Abiturient::getNmae() const
{
    return abiturientNmae;
}

bool Abiturient::getFlagOutOfCompetition() const
{
    return flagOutOfCompetition;
}

bool Abiturient::getFlagFirstOfAll() const
{
    return flagFirstOfAll;
}

bool Abiturient::getFlagOriginalAtestat() const
{
    return flagOriginalAtestat;
}

qreal Abiturient::getPointsTotal() const
{
    return pointsTotal;
}


void Abiturient::setName(const QString &val)
{
    abiturientNmae = val;
}

void Abiturient::setPointsTotal(qreal val)
{
    pointsTotal = val;
}

void Abiturient::setFlagOutOfCompetition(bool val)
{
    flagOutOfCompetition = val;
}

void Abiturient::setFlagFirstOfAll(bool val)
{
    flagFirstOfAll = val;
}

void Abiturient::setFlagOriginalAtestat(bool val)
{
    flagOriginalAtestat = val;
}
