#include "abiturient.h"

Abiturient::Abiturient(int abiturientId, const QString &abiturientName, const qreal abiturientPT, bool abiturientOOC, bool abiturientU, bool abiturientOA, QObject *parent) :
    QObject(parent)
{
    id = abiturientId;
    nmae = abiturientName;
    pointsTotal = abiturientPT;
    flagUrgent = abiturientU;
    flagOutOfCompetition = abiturientOOC;
    flagOriginalAtestat = abiturientOA;
}

QString Abiturient::getNmae() const
{
    return nmae;
}

bool Abiturient::getFlagOutOfCompetition() const
{
    return flagOutOfCompetition;
}

bool Abiturient::getFlagUrgent() const
{
    return flagUrgent;
}

bool Abiturient::getFlagOriginalAtestat() const
{
    return flagOriginalAtestat;
}

qreal Abiturient::getPointsTotal() const
{
    return pointsTotal;
}
