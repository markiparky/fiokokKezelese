#ifndef ADMIN_H
#define ADMIN_H

#include "person.h"

class Admin : public Person
{
public:
    Admin(int id, QString firstName, QString lastName, QDate dateOfBirth, QString password);

    QJsonObject serialize() override;
};

#endif // ADMIN_H
