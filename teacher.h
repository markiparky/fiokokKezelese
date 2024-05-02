#ifndef TEACHER_H
#define TEACHER_H

#include "person.h"

class Teacher : public Person
{

    Q_PROPERTY(int m_osztalyOsztalyfonoke READ osztalyOsztalyfonoke WRITE setOsztalyOsztalyfonoke FINAL)

public:
    Teacher(int id, QString firstName, QString lastName, QDate dateOfBirth, QString password, int osztalyOsztalyfonoke);

    int osztalyOsztalyfonoke();
    void setOsztalyOsztalyfonoke(int newOsztalyOsztalyfonoke);

    QJsonObject serialize() override;

private:
    int m_osztalyOsztalyfonoke;

};

#endif // TEACHER_H
