#ifndef VIEWSTUDENT_H
#define VIEWSTUDENT_H

#include "student.h"

#include <QWidget>



class ViewStudent : public QWidget
{
    Q_OBJECT
public:
    explicit ViewStudent(Student *student, QWidget *parent = nullptr);

signals:

};

#endif // VIEWSTUDENT_H
