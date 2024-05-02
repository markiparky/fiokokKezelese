#ifndef PERSONMANAGER_H
#define PERSONMANAGER_H

#include "person.h"



class PersonManager
{
public:
    PersonManager();

    QList<Person> persons();

    void addPerson(Person person);
    void removePerson(int id);

private:
    QList<Person> m_persons;

};

#endif // PERSONMANAGER_H
