#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "personmanager.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    PersonManager *personManager = new PersonManager();
    Person *loggedInAs = nullptr;
};
#endif // MAINWINDOW_H
