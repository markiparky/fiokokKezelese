#ifndef NEWPERSONCREATION_H
#define NEWPERSONCREATION_H

#include "personmanager.h"
#include <QWidget>

class NewPersonCreation : public QWidget
{
    Q_OBJECT
public:
    explicit NewPersonCreation(PersonManager *personManager, QWidget *parent = nullptr);

private:
    PersonManager *personManager;
signals:

};

#endif // NEWPERSONCREATION_H
