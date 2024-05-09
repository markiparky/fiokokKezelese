#ifndef PERSONSLISTITEM_H
#define PERSONSLISTITEM_H

#include "person.h"
#include <QListWidgetItem>

class PersonsListItem : public QListWidgetItem
{
public:
    PersonsListItem(Person *person);
private:
    Person *person;
};

#endif // PERSONSLISTITEM_H
