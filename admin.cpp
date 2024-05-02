#include "admin.h"

#include <QJsonObject>

Admin::Admin(int id, QString firstName, QString lastName, QDate dateOfBirth, QString password) :
    Person(id, firstName, lastName, dateOfBirth, password)
{

}

QJsonObject Admin::serialize()
{
    QJsonObject object = Person::serialize();

    object["type"] = "ADMIN";

    return object;

}
