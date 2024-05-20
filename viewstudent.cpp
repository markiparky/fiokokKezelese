#include "viewstudent.h"

#include <QCalendarWidget>
#include <QLabel>
#include <QLineEdit>
#include <QString>
#include <QVBoxLayout>

ViewStudent::ViewStudent(Student *student, QWidget *parent)
    : QWidget{parent}
{
    this->setWindowTitle("Diák adatai");

    QVBoxLayout *layout = new QVBoxLayout();
    this->setLayout(layout);

    QLabel *firstNameLabel = new QLabel("Keresztnév: ");
    layout->addWidget(firstNameLabel);
    QLineEdit *firstName = new QLineEdit();
    firstName->setEnabled(false);
    layout->addWidget(firstName);

    QLabel *lastNameLabel = new QLabel("Vezetéknév: ");
    layout->addWidget(lastNameLabel);
    QLineEdit* lastName = new QLineEdit();
    lastName->setEnabled(false);
    layout->addWidget(lastName);

    QLabel *dateOfBirthLabel = new QLabel("Születési dátum: ");
    layout->addWidget(dateOfBirthLabel);
    QCalendarWidget *dateOfBirth = new QCalendarWidget();
    dateOfBirth->setEnabled(false);
    layout->addWidget(dateOfBirth);

    QLabel *gradeClassLabel = new QLabel("Osztály: ");
    layout->addWidget(gradeClassLabel);
    QLineEdit *gradeClass = new QLineEdit();
    gradeClass->setEnabled(false);
    layout->addWidget(gradeClass);

    firstName->setText(student->firstName());
    lastName->setText(student->lastName());
    dateOfBirth->setSelectedDate(student->dateOfBirth());
    gradeClass->setText(QString::number(student->evfolyam()));

}
