#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "personmanager.h"
#include "student.h"
#include "teacher.h"
#include "admin.h"

#include <QDate>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    PersonManager personManager = PersonManager();

    if(personManager.persons().size() == 0){
        Student *student = new Student(1, "first", "last", QDate(2024, 5, 1), "jelszo", 3);
        personManager.addPerson(student);

        Teacher *teacher = new Teacher(2, "teacher_first", "teacher_last", QDate(2023, 5, 2), "123", 3);
        personManager.addPerson(teacher);

        Admin *admin = new Admin(3, "admin_first", "admin_last", QDate(2022, 5, 3), "password");
        personManager.addPerson(admin);

        personManager.saveData();
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

