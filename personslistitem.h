#ifndef PERSONSLISTITEM_H
#define PERSONSLISTITEM_H

#include "person.h"
#include <QListWidgetItem>

class PersonsListItem : public QListWidgetItem
{
public:
    PersonsListItem(Person *person);
    Person* person();
private:
    Person *m_person;
};

#endif // PERSONSLISTITEM_H
