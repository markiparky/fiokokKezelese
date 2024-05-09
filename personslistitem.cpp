#include "personslistitem.h"

PersonsListItem::PersonsListItem(Person *person)
{
    m_person = person;
    this->setText(m_person->lastName() + " " + m_person->firstName());
}

Person* PersonsListItem::person()
{
    return m_person;
}
