#include "personslistitem.h"

PersonsListItem::PersonsListItem(Person *person)
{
    this->person = person;
    this->setText(person->lastName() + " " + person->firstName());
}
