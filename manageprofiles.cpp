#include "admin.h"
#include "manageprofiles.h"
#include "modifyperson.h"
#include "newpersoncreation.h"
#include "personmanager.h"
#include "personslistitem.h"
#include "student.h"
#include "teacher.h"
#include "viewstudent.h"

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
    }else if(Teacher *derived = dynamic_cast<Teacher *>(person)){
        qDebug() << "Teacher";
        displayTeacher(derived);
    }else if(auto derived = dynamic_cast<Admin *>(person)){
        displayAdmin();
    }else{
        qDebug() << "Can't cast!";
    }
}

void ManageProfiles::displayAdmin(){
    this->setWindowTitle("Fiókok kezelése");
    QLabel *label = new QLabel("Fiókok szerkesztése");
    layout->addWidget(label);

    updatePersonList();
    layout->addWidget(listWidget);

    QHBoxLayout *horizontalLayout = new QHBoxLayout();

    QPushButton *addButton = new QPushButton("Új");
    horizontalLayout->addWidget(addButton);

    QPushButton *modifyButton = new QPushButton("Módosítás");
    modifyButton->setEnabled(false);
    horizontalLayout->addWidget(modifyButton);

    QPushButton *removeButton = new QPushButton("Törlés");
    removeButton->setEnabled(false);
    horizontalLayout->addWidget(removeButton);

    connect(listWidget, &QListWidget::itemSelectionChanged, this, [this, removeButton, modifyButton](){
        if(listWidget->selectedItems().size() > 0){
            removeButton->setEnabled(true);
            modifyButton->setEnabled(true);
        }else{
            removeButton->setEnabled(false);
            modifyButton->setEnabled(false);
        }
    });

    connect(removeButton, &QPushButton::clicked, this, [this](){
        // remove persons
        PersonsListItem *selectedItem = dynamic_cast<PersonsListItem *>(listWidget->currentItem());
        this->personManager->removePerson(selectedItem->person()->id());
        personManager->saveData();

        // reload persons
        updatePersonList();
    });

    connect(addButton, &QPushButton::clicked, this, [this](){
        NewPersonCreation *newPersonCreation = new NewPersonCreation(this->personManager);

        connect(newPersonCreation, &NewPersonCreation::newPersonAdded, this, [this]{
            updatePersonList();
        });

        newPersonCreation->show();
    });

    connect(modifyButton, &QPushButton::clicked, this, [this](){
        PersonsListItem *selectedItem = dynamic_cast<PersonsListItem *>(listWidget->currentItem());
        ModifyPerson *modifyPerson =  new ModifyPerson(this->personManager, selectedItem->person());

        connect(modifyPerson, &ModifyPerson::personModified, this, [this]{
            updatePersonList();
        });

        modifyPerson->show();
    });

    layout->addLayout(horizontalLayout);
}

void ManageProfiles::updatePersonList(){
    // reload persons
    listWidget->clear();
    foreach (Person *person, personManager->persons()) {
        PersonsListItem *item = new PersonsListItem(person);
        listWidget->addItem(item);
    }
}

void ManageProfiles::displayTeacher(Teacher *loggedInTeacher){
    this->setWindowTitle("Osztály tagjai");

    QLabel *label = new QLabel("Osztály tagjai:");
    layout->addWidget(label);

    foreach (Person *person, personManager->persons()) {
        if(Student *derived = dynamic_cast<Student *>(person)){
            if(derived->evfolyam() == loggedInTeacher->osztalyOsztalyfonoke()){
                PersonsListItem *item = new PersonsListItem(person);
                listWidget->addItem(item);
            }
        }
    }

    layout->addWidget(listWidget);

    QHBoxLayout *horizontalLayout = new QHBoxLayout();

    QPushButton *viewButton = new QPushButton("Részletek");
    viewButton->setEnabled(false);
    horizontalLayout->addWidget(viewButton);

    connect(viewButton, &QPushButton::clicked, this, [this](){
        PersonsListItem *selectedItem = dynamic_cast<PersonsListItem *>(listWidget->currentItem());
        ViewStudent *viewStudent = new ViewStudent(dynamic_cast<Student *>(selectedItem->person()));
        viewStudent->show();
    });

    connect(listWidget, &QListWidget::itemSelectionChanged, this, [this, viewButton](){
        if(listWidget->selectedItems().size() > 0){
            viewButton->setEnabled(true);
        }else{
            viewButton->setEnabled(false);
        }
    });

    layout->addLayout(horizontalLayout);
}
