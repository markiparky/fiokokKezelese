#ifndef PERSON_H
#define PERSON_H

#include <QString>
#include <QDate>


 class Person
{
    Q_PROPERTY(QString m_firstName READ firstName WRITE setFirstName FINAL)
    Q_PROPERTY(QString m_lastName READ lastName WRITE setlastName FINAL)
    Q_PROPERTY(QDate m_dateOfBirth READ dateOfBirth WRITE setDateOfBirth FINAL)
    Q_PROPERTY(QString m_password WRITE setPassword FINAL)
public:

    Person(int id, QString firstName, QString lastName, QDate dateOfBirth, QString password);

    int id();
    void setId(int newId);

    QString firstName();
    void setFirstName(QString newFirstName);

    QString lastName();
    void setLastName(QString newLastName);

    QDate dateOfBirth();
    void setDateOfBirth(QDate newDateOfBirth);

    void setPassword(QString new_password);
    bool comparePasswords(QString password);

    virtual QJsonObject serialize();

private:
    int m_id;
    QString m_firstName;
    QString m_lastName;
    QDate m_dateOfBirth;
    QString m_password;

};

#endif // PERSON_H
