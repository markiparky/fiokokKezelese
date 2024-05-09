#include "person.h"

#include <QJsonObject>

Person::Person(int id, QString firstName, QString lastName, QDate dateOfBirth, QString password){
    m_id = id;
    m_firstName = firstName;
    m_lastName = lastName;
    m_dateOfBirth = dateOfBirth;
    m_password = password;
}

int Person::id(){
    return m_id;
}

void Person::setId(int newId){
    if(m_id == newId){
        m_id = newId;
    }
}

QString Person::firstName(){
    return m_firstName;
}

void Person::setFirstName(QString newFirstName){
    if(m_firstName.compare(newFirstName) != 0){
        m_firstName = newFirstName;
    }
}

QString Person::lastName(){
    return m_lastName;
}

void Person::setLastName(QString newLastName){
    if(m_lastName.compare(newLastName) != 0){
        m_lastName = newLastName;
    }
}

QDate Person::dateOfBirth(){
    return m_dateOfBirth;
};

void Person::setDateOfBirth(QDate newDateOfBirth){
    if(m_dateOfBirth != newDateOfBirth){
        m_dateOfBirth = newDateOfBirth;
    }
};

void Person::setPassword(QString newPassword){
    if(m_password != newPassword){
        m_password = newPassword;
    }
}

bool Person::comparePasswords(QString password){
    return m_password == password;
}

QJsonObject Person::serialize(){
    QJsonObject object;

    //object["type"] = "PERSON";
    object["id"] = m_id;
    object["firstName"] = m_firstName;
    object["lastName"] = m_lastName;
    object["dateOfBirth"] = m_dateOfBirth.toString();
    object["password"] = m_password;

    return object;
};
