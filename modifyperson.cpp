#include "modifyperson.h"
#include "personmanager.h"
#include "student.h"
#include "teacher.h"
#include "person.h"
#include "admin.h"

#include <QVBoxLayout>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QCalendarWidget>
#include <QMessageBox>



ModifyPerson::ModifyPerson(PersonManager *personManager, Person *person, QWidget *parent)
    : QWidget{parent}, personManager(personManager), person(person)
{
    this->setWindowTitle("Személy szerkesztése");
    this->personManager = personManager;
    this->setLayout(verticalLayout);

    QVBoxLayout *formLayout = new QVBoxLayout();
    verticalLayout->addLayout(formLayout);

    QPushButton *modifyButton = new QPushButton("Személy modosítása");
    verticalLayout->addWidget(modifyButton);

    QHBoxLayout *row = new QHBoxLayout();
    formLayout->addLayout(row);

    QLabel* AdminLabel = new QLabel("Admin");
    QLabel* TeacherLabel = new QLabel("Tanár");
    QLabel* StudentLabel = new QLabel("Diák");

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

    FirstName->setText(person->firstName());
    LastName->setText(person->lastName());
    DateOfBirth->setSelectedDate(person->dateOfBirth());
    Password->setText(person->password());

    if (auto student = dynamic_cast<Student*>(person)) {
        row->addWidget(StudentLabel);
        GradeClassLabel->show();
        GradeClass->show();
        formLayout->addWidget(GradeClassLabel);
        formLayout->addWidget(GradeClass);
        GradeClass->setText(QString::number(student->evfolyam()));
    } else if (auto teacher = dynamic_cast<Teacher*>(person)) {
        row->addWidget(TeacherLabel);
        HeadTeacherLabel->show();
        HeadTeacher->show();
        formLayout->addWidget(HeadTeacherLabel);
        formLayout->addWidget(HeadTeacher);
        HeadTeacher->setText(QString::number(teacher->osztalyOsztalyfonoke()));
    } else if (auto admin = dynamic_cast<Admin*>(person)) {
        row->addWidget(AdminLabel);
    }


    connect(modifyButton, &QPushButton::clicked, this, [this, FirstName, LastName, Password, GradeClass, HeadTeacher, DateOfBirth]{
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

        if (auto student = dynamic_cast<Student*>(this->person)) {
            int GradeClassInt = GradeClass->text().toInt();
            if (GradeClassInt == 0) {
                QMessageBox::critical(this, "Hiba!", "Az űrlap hiányzó mezőket tartalmaz.");
                return;
            }
            student->setFirstName(FirstNameString);
            student->setLastName(LastNameString);
            student->setDateOfBirth(DateOfBirthString);
            student->setPassword(PasswordString);
            student->setEvfolyam(GradeClassInt);
        } else if (auto teacher = dynamic_cast<Teacher*>(this->person)) {
            int HeadTeacherInt = HeadTeacher->text().toInt();
            if (HeadTeacherInt == 0) {
                QMessageBox::critical(this, "Hiba!", "Az űrlap hiányzó mezőket tartalmaz.");
                return;
            }
            teacher->setFirstName(FirstNameString);
            teacher->setLastName(LastNameString);
            teacher->setDateOfBirth(DateOfBirthString);
            teacher->setPassword(PasswordString);
            teacher->setOsztalyOsztalyfonoke(HeadTeacherInt);
        } else if (auto admin = dynamic_cast<Admin*>(this->person)) {
            admin->setFirstName(FirstNameString);
            admin->setLastName(LastNameString);
            admin->setDateOfBirth(DateOfBirthString);
            admin->setPassword(PasswordString);
        }

        this->personManager->modifyPerson(this->person);
        this->personManager->saveData();
        emit personModified();
        this->close();
    });
}
