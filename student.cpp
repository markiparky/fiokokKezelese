#include "student.h"

Student::Student(int id, QString firstName, QString lastName, QDate dateOfBirth, int evfolyam) :
    Person(id, firstName, lastName, dateOfBirth)
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
