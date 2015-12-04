#include "datalayer.h"

DataLayer::DataLayer()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString name = "data.db";
    db.setDatabaseName(name);
}

DataLayer::DataLayer(string dbName)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString name = QString::fromStdString(dbName);
    db.setDatabaseName(name);
}

void DataLayer::createTables()
{
    db.open();
    QSqlQuery query(db);


    query.exec("create table Person(id INTEGER PRIMARY KEY AUTOINCREMENT,name varchar(100),gender varchar(6),birthyear int,deathyear int)");
    query.exec("create table Computer(id INTEGER PRIMARY KEY AUTOINCREMENT,name varchar(100),byear int,type varchar(100),made varchar(10))");
    query.exec("create table CPlink(id INTEGER PRIMARY KEY AUTOINCREMENT,personId int, computerId int, FOREIGN KEY(personId) REFERENCES Person(id),FOREIGN KEY(computerId) REFERENCES Computer(id))");
    db.close();
}

void DataLayer::dropTables()
{
    db.open();
    QSqlQuery query(db);
    query.exec("drop table CPlink");
    query.exec("drop table Person");
    query.exec("drop table Computer");
    db.close();
}




/*
 *
 *
 *
 * Functions that modify Person table
 *
 *
 *
 *
 *
 * */

void DataLayer::insertToDbPerson(Person newPerson)
{
    QString _name = QString::fromStdString(newPerson.getName());
    QString _gender = QString::fromStdString(newPerson.getGender());
    db.open();
    QSqlQuery query(db);
    query.prepare("insert into Person(name,gender,birthyear,deathyear) values(?,?,?,?)");
    query.addBindValue(_name);
    query.addBindValue(_gender);
    query.addBindValue(newPerson.getBirthYear());
    query.addBindValue(newPerson.getDeathYear());
    query.exec();
    db.close();
}

vector<Person> DataLayer::loadDbPerson()
{
    vector<Person> personList;
    db.open();
    QSqlQuery query(db);
    query.exec("select * from Person");

    while(query.next())
    {
        string name = query.value("name").toString().toStdString();
        string gender = query.value("gender").toString().toStdString();
        int byear = query.value("birthyear").toInt();
        int dyear = query.value("deathyear").toInt();
        int id = query.value("id").toInt();
        Person newPerson(name,gender,byear,dyear,id);
        personList.push_back(newPerson);
    }
    db.close();
    return personList;
}


void DataLayer::deleteFromDbPerson(Person delPerson)
{
    db.open();
    QSqlQuery query(db);
    query.prepare("Delete from Person where id=?");
    query.addBindValue(delPerson.getId());
    query.exec();
    db.close();
}






/*
 *
 *
 *
 *
 * Functions that modify Computer
 *
 *
 *
 *
 * */


void DataLayer::insertToDbComputer(Computer newComputer)
{
    QString _name = QString::fromStdString(newComputer.getName());
    QString _type = QString::fromStdString(newComputer.getType());
    QString _made = QString::fromStdString(newComputer.getBuiltComputer());
    db.open();
    QSqlQuery query(db);
    query.prepare("insert into Computer(name,byear,type,made) values(?,?,?,?)");
    query.addBindValue(_name);
    query.addBindValue(newComputer.getBuiltYear());
    query.addBindValue(_type);
    query.addBindValue(_made);
    query.exec();
    db.close();
}

vector<Computer> DataLayer::loadDbComputer()
{
    vector<Computer> computerList;
    db.open();
    QSqlQuery query(db);
    query.exec("select * from Computer");

    while(query.next())
    {
        string name = query.value("name").toString().toStdString();
        int byear = query.value("byear").toInt();
        string type = query.value("type").toString().toStdString();
        string made = query.value("made").toString().toStdString();
        int id = query.value("id").toInt();
        Computer newComputer(name,byear,type,made,id);
        computerList.push_back(newComputer);
    }
    db.close();
    return computerList;
}


void DataLayer::deleteFromDbComputer(Computer delComputer)
{
    db.open();
    QSqlQuery query(db);
    query.prepare("Delete from Computer where id=?");
    query.addBindValue(delComputer.getId());
    query.exec();
    db.close();
}




/*
 *
 *
 *
 *
 * Functions that modify the link between Computers and Person (CPlink)
 *
 *
 *
 *
 *
 * */

void DataLayer::insertToDbCPLink(Computer newComputer, Person newPerson)
{
    db.open();
    QSqlQuery query(db);
    query.prepare("insert into CPlink(personId,computerId) values(?,?)");
    query.addBindValue(newPerson.getId());
    query.addBindValue(newComputer.getId());
    query.exec();
    db.close();
}

vector<CPlink> DataLayer::loadDbCPlink()
{
    vector<CPlink> newList;
    db.open();
    QSqlQuery query(db);
    query.exec("Select * from CPlink");

    while(query.next())
    {
        int computerId = query.value("computerId").toInt();
        int personId = query.value("personId").toInt();
        int id = query.value("id").toInt();

        CPlink newLink(computerId,personId,id);
        newList.push_back(newLink);
    }
    db.close();
    return newList;
}


void DataLayer::deleteFromDbLink(CPlink delLink)
{
    db.open();
    QSqlQuery query(db);
    query.prepare("Delete from CPlink where id=?");
    query.addBindValue(delLink.getLinkId());
    query.exec();
    db.close();
}
