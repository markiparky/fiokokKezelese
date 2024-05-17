#include "newpersoncreation.h"
#include "personmanager.h"
#include "student.h"
#include "teacher.h"
//#include "admin.h"
#include "person.h"
//#include "manageprofiles.h"
#include "newpersoncreation.h"

#include <QLabel>
#include <QVBoxLayout>
#include <QDebug>
#include <QListView>
#include <QStandardItemModel>
#include <QListWidget>
#include <QPushButton>
#include <QRadioButton>
#include <QMessageBox>
#include "QFile"
#include <QCalendarWidget>

NewPersonCreation::NewPersonCreation(PersonManager *personManager, QWidget *parent)
    : QWidget{parent}
{
    this->setWindowTitle("Új személy hozzáadása");
    this->personManager = personManager;
    this->setLayout(verticalLayout);

    QVBoxLayout *formLayout = new QVBoxLayout();
    verticalLayout->addLayout(formLayout);

    QPushButton* AddBtn = new QPushButton("Személy hozzádása");
    verticalLayout->addWidget(AddBtn);

    QHBoxLayout *row = new QHBoxLayout();
    formLayout->addLayout(row);

    QRadioButton *SelectStudent = new QRadioButton("Diák", this);
    row->addWidget(SelectStudent);

    QRadioButton *SelectTeacher = new QRadioButton("Tanár", this);
    row->addWidget(SelectTeacher);

    QLabel* FirstNameLabel = new QLabel("Keresztnév: ");
    formLayout->addWidget(FirstNameLabel);
    QLineEdit* FirstName = new QLineEdit();
    formLayout->addWidget(FirstName);

    QLabel* LastNameLabel = new QLabel("Vezetéknév: ");
    formLayout->addWidget(LastNameLabel);
    QLineEdit* LastName = new QLineEdit();
    formLayout->addWidget(LastName);

    QLabel* DateOfBirthLabel = new QLabel("Születési dátum: ");
    formLayout->addWidget(DateOfBirthLabel);
    QCalendarWidget* DateOfBirth = new QCalendarWidget();
    formLayout->addWidget(DateOfBirth);

    QLabel* PasswordLabel = new QLabel("Jelszó: ");
    formLayout->addWidget(PasswordLabel);
    QLineEdit* Password = new QLineEdit();
    formLayout->addWidget(Password);

    QLabel* GradeClassLabel = new QLabel("Osztály: ");
    QLineEdit* GradeClass = new QLineEdit();

    QLabel* HeadTeacherLabel = new QLabel("Osztály osztályfőnöke: ");
    QLineEdit* HeadTeacher = new QLineEdit();

    connect(AddBtn, &QPushButton::clicked, this, [this, SelectStudent, SelectTeacher, FirstName, LastName, Password, GradeClass, HeadTeacher, DateOfBirth]{
        QString FirstNameString = FirstName->text();
        QString LastNameString = LastName->text();
        QString PasswordString = Password->text();
        QDate DateOfBirthString = DateOfBirth->selectedDate();

        int GradeClassInt = GradeClass->text().toInt();
        int HeadTeacherInt = HeadTeacher->text().toInt();

        if(FirstNameString.isEmpty() || LastNameString.isEmpty() || PasswordString.isEmpty() || DateOfBirthString.isNull()){
            QMessageBox *errorMessage = new QMessageBox(QMessageBox::Critical, "Hiba!", "Az űrlap hiányzó mezőket tartalmaz.");
            errorMessage->show();
            return;
        }

        if(SelectStudent->isChecked()){

            if(GradeClassInt == 0){
                QMessageBox *errorMessage = new QMessageBox(QMessageBox::Critical, "Hiba!", "Az űrlap hiányzó mezőket tartalmaz.");
                errorMessage->show();
                return;
            }

            Student *newstudent = new Student(
                6,
                FirstNameString,
                LastNameString,
                DateOfBirthString,
                PasswordString,
                GradeClassInt
            );
            this->personManager->addPerson(newstudent);

        }else if(SelectTeacher->isChecked()){
            if(HeadTeacherInt == 0){
                QMessageBox *errorMessage = new QMessageBox(QMessageBox::Critical, "Hiba!", "Az űrlap hiányzó mezőket tartalmaz.");
                errorMessage->show();
                return;
            }
            Teacher *newteacher = new Teacher(
                7,
                FirstNameString,
                LastNameString,
                DateOfBirthString,
                PasswordString,
                HeadTeacherInt
            );

            this->personManager->addPerson(newteacher);
        }
        this->personManager->saveData();
        emit newPersonAdded();
        this->close();

    });

    connect(SelectStudent, &QRadioButton::toggled, this, [this, SelectStudent, HeadTeacherLabel, HeadTeacher, GradeClass, GradeClassLabel, formLayout]{
        if(SelectStudent->isChecked()){
            formLayout->removeWidget(HeadTeacherLabel);
            HeadTeacherLabel->setVisible(false);
            formLayout->removeWidget(HeadTeacher);

            formLayout->addWidget(GradeClassLabel);
            GradeClassLabel->setVisible(true);
            formLayout->addWidget(GradeClass);
        }
    });

    connect(SelectTeacher, &QRadioButton::toggled, this, [this, SelectTeacher, HeadTeacherLabel, HeadTeacher, GradeClass, GradeClassLabel, formLayout]{
        if(SelectTeacher->isChecked()){
            formLayout->removeWidget(GradeClassLabel);
            GradeClassLabel->setVisible(false);
            formLayout->removeWidget(GradeClass);

            formLayout->addWidget(HeadTeacherLabel);
            HeadTeacherLabel->setVisible(true);
            formLayout->addWidget(HeadTeacher);
        }
    });



}









