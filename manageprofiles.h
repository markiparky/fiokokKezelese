#ifndef MANAGEPROFILES_H
#define MANAGEPROFILES_H

#include "person.h"
#include "personmanager.h"
#include <QListWidget>
#include <QVBoxLayout>
#include <QWidget>

class ManageProfiles : public QWidget
{
    Q_OBJECT
public:
    ManageProfiles(Person *person, PersonManager *personManager, QWidget *parent = nullptr);

private:
    void displayAdmin();
    void updatePersonList();
    PersonManager *personManager;
    QVBoxLayout *layout = new QVBoxLayout();
    QListWidget *listWidget = new QListWidget();
};

#endif // MANAGEPROFILES_H
