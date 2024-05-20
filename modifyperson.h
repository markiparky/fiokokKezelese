#ifndef MODIFYPERSON_H
#define MODIFYPERSON_H

#include <QVBoxLayout>
#include <QLineEdit>

#include "personmanager.h"

#include <QWidget>

class ModifyPerson : public QWidget
{
    Q_OBJECT
public:
    explicit ModifyPerson(PersonManager *personManager, Person *person, QWidget *parent = nullptr);

private:
    PersonManager *personManager;
    Person *person;
    QVBoxLayout *verticalLayout = new QVBoxLayout();

signals:
    void personModified();
};

#endif // MODIFYPERSON_H
