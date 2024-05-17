#ifndef NEWPERSONCREATION_H
#define NEWPERSONCREATION_H

#include <QWidget>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QDebug>
#include <QListView>
#include <QStandardItemModel>
#include <QListWidget>
#include <QPushButton>
#include <QRadioButton>
#include "QFile"

#include "personmanager.h"

class NewPersonCreation : public QWidget
{
    Q_OBJECT
public:
    explicit NewPersonCreation(PersonManager *personManager, QWidget *parent = nullptr);

private:
    PersonManager *personManager;
    QVBoxLayout *verticalLayout = new QVBoxLayout();

signals:
    void newPersonAdded();
};

#endif // NEWPERSONCREATION_H
