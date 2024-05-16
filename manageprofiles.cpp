#include "admin.h"
#include "manageprofiles.h"
#include "newpersoncreation.h"
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
#include <QPushButton>

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

    QHBoxLayout *horizontalLayout = new QHBoxLayout();

    QPushButton *addButton = new QPushButton("Új");
    horizontalLayout->addWidget(addButton);

    QPushButton *removeButton = new QPushButton("Törlés");
    removeButton->setEnabled(false);
    horizontalLayout->addWidget(removeButton);


    connect(listWidget, &QListWidget::itemSelectionChanged, this, [this, listWidget, removeButton](){
        if(listWidget->selectedItems().size() > 0){
            removeButton->setEnabled(true);
        }else{
            removeButton->setEnabled(false);
        }
    });

    connect(removeButton, &QPushButton::clicked, this, [this, listWidget](){
        // remove persons
        PersonsListItem *selectedItem = dynamic_cast<PersonsListItem *>(listWidget->currentItem());
        this->personManager->removePerson(selectedItem->person()->id());
        personManager->saveData();

        // reload persons
        listWidget->clear();
        foreach (Person *person, personManager->persons()) {
            PersonsListItem *item = new PersonsListItem(person);
            listWidget->addItem(item);
        }
    });

    connect(addButton, &QPushButton::clicked, this, [this](){
        NewPersonCreation *newPersonCreation = new NewPersonCreation(this->personManager);
        newPersonCreation->show();

    });

    layout->addLayout(horizontalLayout);
}
