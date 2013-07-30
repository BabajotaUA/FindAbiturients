#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include <QObject>
#include "abiturient.h"

class University : public QObject
{
    Q_OBJECT
public:
    explicit University(const QString &uName, QObject *parent = nullptr);
    virtual ~University() {}

    void addAbiturient();
    QList<Abiturient *> *getAbiturientList();

private:
    QList<Abiturient*> abiturients;
    QString universityName;
        
};

#endif // UNIVERSITY_H
