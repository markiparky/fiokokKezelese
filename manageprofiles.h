#ifndef MANAGEPROFILES_H
#define MANAGEPROFILES_H

#include "person.h"
#include "personmanager.h"
#include <QVBoxLayout>
#include <QWidget>

class ManageProfiles : public QWidget
{
    Q_OBJECT
public:
    ManageProfiles(Person *person, PersonManager *personManager, QWidget *parent = nullptr);

private:
    void displayAdmin();
    PersonManager *personManager;
    QVBoxLayout *layout = new QVBoxLayout();
};

#endif // MANAGEPROFILES_H
