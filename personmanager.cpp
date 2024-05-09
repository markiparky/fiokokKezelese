#include "admin.h"
#include "personmanager.h"
#include "student.h"
#include "teacher.h"

#include <QFile>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

PersonManager::PersonManager()
{
    loadData();
}

QList<Person *> PersonManager::persons()
{
    return m_persons;
}

void PersonManager::addPerson(Person *person)
{
    int currentMaxId = -1;

    foreach (Person *p, m_persons) {
        if(p->id() > currentMaxId){
            currentMaxId = p->id();
        }
    }

    person->setId(currentMaxId + 1);
    m_persons.append(person);
}

void PersonManager::removePerson(int id)
{
    int personIndex = -1;
    for(int i = 0; i< m_persons.size(); i++){
        Person *person = m_persons.at(i);
        if(person->id() == id){
            personIndex = i;
            qDebug() << "found person";
        }
    }

    if(personIndex == -1){
        qDebug() << "person id not found!";
        return;
    }

    m_persons.removeAt(personIndex);
}

void PersonManager::loadData()
{
    QString dataPath = "data.json";

    if(!QFile::exists(dataPath)){
        saveData();
    }

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        // nem sikerült megnyitni!
        qDebug() << "Nem sikerült megnyitni a fájlt!";
        return;
    }


    QString text;
    while(!file.atEnd()){
        QString line = file.readLine();
        text += line;
    }

    file.close();

    QJsonDocument document = QJsonDocument::fromJson(text.toUtf8());
    QJsonArray persons = document["persons"].toArray();

    for(int i = 0; i < persons.count(); i++){
        QJsonObject person = persons[i].toObject();

        if(person["type"] == "STUDENT"){
            Student *student = new Student(
                person["id"].toInt(),
                person["firstName"].toString(),
                person["lastName"].toString(),
                QDate::fromString(person["dateOfBirth"].toString()),
                person["password"].toString(),
                person["evfolyam"].toInt()
                );

            m_persons.append(student);
        }else if(person["type"] == "TEACHER"){
            Teacher *teacher = new Teacher(
                person["id"].toInt(),
                person["firstName"].toString(),
                person["lastName"].toString(),
                QDate::fromString(person["dateOfBirth"].toString()),
                person["password"].toString(),
                person["osztalyOsztalyfonoke"].toInt()
                );
            m_persons.append(teacher);
        }else if(person["type"] == "ADMIN"){
            Admin *admin = new Admin(
                person["id"].toInt(),
                person["firstName"].toString(),
                person["lastName"].toString(),
                QDate::fromString(person["dateOfBirth"].toString()),
                person["password"].toString()
                );

            m_persons.append(admin);
        }else{
            qDebug() << "Invalid person type: " << person["type"].toString();
        }

    }
}

void PersonManager::saveData()
{
    QJsonDocument document;

    QJsonArray persons;
    foreach (Person *person, m_persons) {
        if(auto derived = dynamic_cast<Student *>(person)){
            persons.append(derived->serialize());
        }else if(auto derived = dynamic_cast<Teacher *>(person)){
            persons.append(derived->serialize());
        }else if(auto derived = dynamic_cast<Admin *>(person)){
            persons.append(derived->serialize());
        }else{
            qDebug() << person->serialize();
            qDebug() << "Can't cast!";
        }

    }

    QJsonObject mainObject;
    mainObject["persons"] = persons;
    document.setObject(mainObject);

    if(!file.open(QIODevice::WriteOnly | QIODeviceBase::Text)){
        qDebug() << "Nem sikerült megnyitni a fájlt";
        return;
    }

    file.write(
        document.toJson(QJsonDocument::Indented)
    );

    file.close();

    qDebug() << "Felhasználói adatok mentve.";
}



