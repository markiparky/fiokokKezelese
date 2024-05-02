#ifndef STUDENT_H
#define STUDENT_H

#include "person.h"

class Student : public Person
{

Q_PROPERTY(int m_evfolyam READ evfolyam WRITE setEvfolyam FINAL)

public:
    Student(int id, QString firstName, QString lastName, QDate dateOfBirth, QString password, int evfolyam);

    int evfolyam();
    void setEvfolyam(int newEvfolyam);

    QJsonObject serialize() override;

private:
    int m_evfolyam;
};

#endif // STUDENT_H
