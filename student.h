#ifndef STUDENT_H
#define STUDENT_H

#include "person.h"

class Student : public Person
{
public:
    Student(int id, QString firstName, QString lastName, QDate dateOfBirth, int evfolyam);

    int evfolyam();
    void setEvfolyam(int newEvfolyam);

private:
    int m_evfolyam;
};

#endif // STUDENT_H
