#include "admin.h"
#include "manageprofiles.h"
#include "personmanager.h"
#include "personslistitem.h"
#include "student.h"
#include "teacher.h"

#include <QLabel>
#include <QVBoxLayout>
#include <QDebug>
#include <QListView>
#include <QStandardItemModel>
#include <QListWidget>

ManageProfiles::ManageProfiles(Person *person, PersonManager *personManager, QWidget *parent) : QWidget{parent}
{
    this->personManager = personManager;
    this->setLayout(layout);

    if(auto derived = dynamic_cast<Student *>(person)){
        qDebug() << "Student";
    }else if(auto derived = dynamic_cast<Teacher *>(person)){
        qDebug() << "Teacher";
    }else if(auto derived = dynamic_cast<Admin *>(person)){
        displayAdmin();
    }else{
        qDebug() << "Can't cast!";
    }
}

void ManageProfiles::displayAdmin(){

    QLabel *label = new QLabel("Fiókok szerkesztése");
    layout->addWidget(label);

    QListWidget *listWidget = new QListWidget();

    foreach (Person *person, personManager->persons()) {
        PersonsListItem *item = new PersonsListItem(person);
        listWidget->addItem(item);
    }

    layout->addWidget(listWidget);
}
