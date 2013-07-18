#ifndef ABITURIENT_H
#define ABITURIENT_H

#include <QObject>

class Abiturient : public QObject
{
    Q_OBJECT
public:
    explicit Abiturient(int abiturientId, const QString &abiturientName, const qreal abiturientPT, bool abiturientOOC, bool abiturientU, bool abiturientOA, QObject *parent = nullptr);

    QString getNmae() const;
    bool getFlagOutOfCompetition() const;
    bool getFlagUrgent() const;
    bool getFlagOriginalAtestat() const;
    qreal getPointsTotal() const;

private:
    QString nmae;
    qreal pointsTotal;
    int id;
    bool flagOutOfCompetition;
    bool flagUrgent;
    bool flagOriginalAtestat;

};

#endif // ABITURIENT_H
