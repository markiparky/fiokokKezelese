#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "personmanager.h"
#include "student.h"
#include "teacher.h"
#include "admin.h"
#include "manageprofiles.h"

#include <QDebug>
#include <QDate>

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

    // ---- Setting logged in user manually ----
    foreach(Person *person, personManager->persons()){
        if(Admin *admin = dynamic_cast<Admin *>(person)){
            loggedInAs = admin;
            break;
        }
    }

    if(loggedInAs == nullptr){
        qDebug() << "Can't find admin user";
    }
    // ---- /Setting logged in user manually ----

    connect(ui->manageProfiles, &QAction::triggered, this, [this](){
        ManageProfiles *manageProfiles = new ManageProfiles(loggedInAs, personManager);
        manageProfiles->show();
    });


}

MainWindow::~MainWindow()
{
    delete ui;
}

