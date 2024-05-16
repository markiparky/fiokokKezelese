#include "newpersoncreation.h"

NewPersonCreation::NewPersonCreation(PersonManager *personManager, QWidget *parent)
    : QWidget{parent}
{
    this->personManager = personManager;
}
