#include "student.h"

#include <QJsonObject>

Student::Student(int id, QString firstName, QString lastName, QDate dateOfBirth, QString password, int evfolyam) :
    Person(id, firstName, lastName, dateOfBirth, password)
{
    m_evfolyam = evfolyam;
}

int Student::evfolyam(){
    return m_evfolyam;
}

void Student::setEvfolyam(int newEvfolyam){
    if(m_evfolyam != newEvfolyam){
        m_evfolyam = newEvfolyam;
    }
}


QJsonObject Student::serialize(){
    QJsonObject object = Person::serialize();

    object["type"] = "STUDENT";
    object["evfolyam"] = m_evfolyam;

    return object;
}
