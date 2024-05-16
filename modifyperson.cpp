#include "modifyperson.h"

ModifyPerson::ModifyPerson(PersonManager *personManager, Person *person, QWidget *parent)
    : QWidget{parent}
{
    this->personManager = personManager;
}
