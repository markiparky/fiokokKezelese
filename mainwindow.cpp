#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "personmanager.h"
#include "student.h"
#include "teacher.h"
#include "admin.h"
#include "manageprofiles.h"

#include <QDebug>
#include <QDate>
#include <QComboBox>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    if(personManager->persons().size() == 0){
        Student *student = new Student(1, "first", "last", QDate(2024, 5, 1), "jelszo", 3);
        personManager->addPerson(student);

        Teacher *teacher = new Teacher(2, "teacher_first", "teacher_last", QDate(2023, 5, 2), "123", 3);
        personManager->addPerson(teacher);

        Admin *admin = new Admin(3, "admin_first", "admin_last", QDate(2022, 5, 3), "password");
        personManager->addPerson(admin);

        personManager->saveData();
    }

    connect(ui->manageProfiles, &QAction::triggered, this, [this](){
        ManageProfiles *manageProfiles = new ManageProfiles(loggedInAs, personManager);
        manageProfiles->show();
    });

    // --- user selector for development only ---
    if(personManager->persons().size() > 0){
        loggedInAs = personManager->persons().first();
    }else{
        qDebug() << "No user in the database, can't set logged in user automatically.";
    }

    foreach (Person *person, personManager->persons()) {
        this->ui->usersComboBox->addItem(person->lastName() + " " + person->firstName(), person->id());
    }

    connect(this->ui->usersComboBox, &QComboBox::currentIndexChanged, this, [this]{
        this->loggedInAs = nullptr;
        foreach(Person *person, this->personManager->persons()){
            if(person->id() == this->ui->usersComboBox->currentData().toInt()){
                this->loggedInAs = person;
                break;
            }
        }

        if(this->loggedInAs == nullptr){
            qDebug() << "Can't find user";
        }
    });


    connect(this->ui->refreshButton, &QPushButton::clicked, this, [this]{
        this->ui->usersComboBox->clear();
        foreach (Person *person, this->personManager->persons()) {
            this->ui->usersComboBox->addItem(person->lastName() + " " + person->firstName(), person->id());
        }
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

