#ifndef MODIFYPERSON_H
#define MODIFYPERSON_H

#include "personmanager.h"

#include <QWidget>

class ModifyPerson : public QWidget
{
    Q_OBJECT
public:
    explicit ModifyPerson(PersonManager *personManager, Person *person, QWidget *parent = nullptr);

private:
    PersonManager *personManager;

signals:

};

#endif // MODIFYPERSON_H
