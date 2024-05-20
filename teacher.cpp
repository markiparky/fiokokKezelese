#include "teacher.h"

#include <QJsonObject>

Teacher::Teacher(int id, QString firstName, QString lastName, QDate dateOfBirth, QString password, int osztalyOsztalyfonoke) :
    Person(id, firstName, lastName, dateOfBirth, password)
{
    m_osztalyOsztalyfonoke = osztalyOsztalyfonoke;
}


int Teacher::osztalyOsztalyfonoke(){
    return m_osztalyOsztalyfonoke;
}

void Teacher::setOsztalyOsztalyfonoke(int newOsztalyOsztalyfonoke){
    if(m_osztalyOsztalyfonoke != newOsztalyOsztalyfonoke){
        m_osztalyOsztalyfonoke = newOsztalyOsztalyfonoke;
    }
}

QJsonObject Teacher::serialize()
{
    QJsonObject object = Person::serialize();

    object["type"] = "TEACHER";
    object["osztalyOsztalyfonoke"] = m_osztalyOsztalyfonoke;

    return object;
}
