#ifndef PERSONMANAGER_H
#define PERSONMANAGER_H

#include "person.h"
#include "QFile"

class PersonManager
{
public:
    PersonManager();

    QList<Person *> persons();

    void addPerson(Person *person);
   //void removePerson(int id);

    void saveData();

private:
    QFile file = QFile("data.json");

    QList<Person *> m_persons;

    void loadData();
};

#endif // PERSONMANAGER_H
