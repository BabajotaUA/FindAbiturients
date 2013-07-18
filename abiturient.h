#ifndef ABITURIENT_H
#define ABITURIENT_H

#include <QObject>

class Abiturient : public QObject
{
    Q_OBJECT
public:
    explicit Abiturient(QObject *parent = nullptr);

    QString getNmae() const;
    bool getFlagOutOfCompetition() const;
    bool getFlagFirstOfAll() const;
    bool getFlagOriginalAtestat() const;
    qreal getPointsTotal() const;
    int getId() const;

    void setId(int value);
    void setName(const QString &val);
    void setPointsTotal(qreal val);
    void setFlagOutOfCompetition(bool val);
    void setFlagFirstOfAll(bool val);
    void setFlagOriginalAtestat(bool val);

private:
    QString abiturientNmae;
    qreal pointsTotal;
    int id;
    bool flagOutOfCompetition;
    bool flagFirstOfAll;
    bool flagOriginalAtestat;
};

#endif // ABITURIENT_H
