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


    query.exec("create table Person(id INTEGER PRIMARY KEY AUTOINCREMENT,pname varchar(100),gender varchar(6),birthyear int,deathyear int)");
    query.exec("create table Computer(id INTEGER PRIMARY KEY AUTOINCREMENT,cname varchar(100),byear int,type varchar(100),made varchar(10))");
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
    query.prepare("insert into Person(pname,gender,birthyear,deathyear) values(?,?,?,?)");
    query.addBindValue(_name);
    query.addBindValue(_gender);
    query.addBindValue(newPerson.getBirthYear());
    query.addBindValue(newPerson.getDeathYear());
    query.exec();
    db.close();
}

vector<Person> DataLayer::updateDbPerson(Person updPerson)
{
    QString _name = QString::fromStdString(updPerson.getName());
    QString _gender = QString::fromStdString(updPerson.getGender());
    db.open();
    QSqlQuery query(db);
    query.prepare("update Person set pname=?,gender=?,birthyear=?,deathyear=? where id=?");
    query.addBindValue(_name);
    query.addBindValue(_gender);
    query.addBindValue(updPerson.getBirthYear());
    query.addBindValue(updPerson.getDeathYear());
    query.addBindValue(updPerson.getId());
    query.exec();
    db.close();
    return loadDbPerson();
}

vector<Person> DataLayer::loadDbPerson()
{
    vector<Person> personList;
    db.open();
    QSqlQuery query(db);
    query.exec("select * from Person");

    while(query.next())
    {
        string name = query.value("pname").toString().toStdString();
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

vector<Person> DataLayer::loadDbPersonSort(string column,bool ascending)
{
    string com;
    if(ascending)
    {
        com = "select * from Person order by " + column + " asc";
    }
    else
    {
        com = "select * from Person order by " + column + " desc";
    }
    QString command = QString::fromStdString(com);
    vector<Person> personList;
    db.open();
    QSqlQuery query(db);
    query.exec(command);

    while(query.next())
    {
        string name = query.value("pname").toString().toStdString();
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

vector<Person> DataLayer::searchDbPerson(string column, string value)
{
    string com;
    com = "select * from Person where " + column + " like " + "'%" + value +"%'";
    QString command = QString::fromStdString(com);
    vector<Person> personList;
    db.open();
    QSqlQuery query(db);
    query.exec(command);

    while(query.next())
    {
        string name = query.value("pname").toString().toStdString();
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

Person DataLayer::getPersonFromId(int id)
{
    db.open();
    QSqlQuery query(db);
    query.prepare("Select * from Person where id=?");
    query.addBindValue(id);
    query.exec();

    Person newPerson;
    while(query.next())
    {
        string name = query.value("pname").toString().toStdString();
        string gender = query.value("gender").toString().toStdString();
        int byear = query.value("birthyear").toInt();
        int dyear = query.value("deathyear").toInt();
        int id = query.value("id").toInt();
        newPerson = Person(name,gender,byear,dyear,id);
    }
    db.close();

    return newPerson;
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
    query.prepare("insert into Computer(cname,byear,type,made) values(?,?,?,?)");
    query.addBindValue(_name);
    query.addBindValue(newComputer.getBuiltYear());
    query.addBindValue(_type);
    query.addBindValue(_made);
    query.exec();
    db.close();
}

vector<Computer> DataLayer::updateDbComputer(Computer updComputer)
{
    QString _name = QString::fromStdString(updComputer.getName());
    QString _type = QString::fromStdString(updComputer.getType());
    QString _made = QString::fromStdString(updComputer.getBuiltComputer());
    db.open();
    QSqlQuery query(db);
    query.prepare("update Computer set cname=?,byear=?,type=?,made=? where id=?");
    query.addBindValue(_name);
    query.addBindValue(updComputer.getBuiltYear());
    query.addBindValue(_type);
    query.addBindValue(_made);
    query.addBindValue(updComputer.getId());
    query.exec();
    db.close();
    return loadDbComputer();
}

vector<Computer> DataLayer::loadDbComputer()
{
    vector<Computer> computerList;
    db.open();
    QSqlQuery query(db);
    query.exec("select * from Computer");

    while(query.next())
    {
        string name = query.value("cname").toString().toStdString();
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

vector<Computer> DataLayer::loadDbComputerSort(string column,bool ascending)
{
    string com;
    if(ascending)
    {
        com = "select * from Computer order by " + column + " asc";
    }
    else
    {
        com = "select * from Computer order by " + column + " desc";
    }
    QString command = QString::fromStdString(com);
    vector<Computer> computerList;
    db.open();
    QSqlQuery query(db);
    query.exec(command);

    while(query.next())
    {
        string name = query.value("cname").toString().toStdString();
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

vector<Computer> DataLayer::searchDbComputer(string column, string value)
{
    string com;
    com = "select * from Computer where " + column + " like " + "'%" + value + "%'";
    QString command = QString::fromStdString(com);
    vector<Computer> computerList;
    db.open();
    QSqlQuery query(db);
    query.exec(command);

    while(query.next())
    {
        string name = query.value("cname").toString().toStdString();
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

Computer DataLayer::getComputerFromId(int id)
{
    db.open();
    QSqlQuery query(db);
    query.prepare("Select * from Computer where id=?");
    query.addBindValue(id);
    query.exec();

    Computer newComputer;
    while(query.next())
    {
        string name = query.value("cname").toString().toStdString();
        string type = query.value("type").toString().toStdString();
        int byear = query.value("byear").toInt();
        string made = query.value("made").toString().toStdString();
        int id = query.value("id").toInt();
        newComputer = Computer(name,byear,type,made,id);
    }
    db.close();

    return newComputer;

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

vector<CPlink> DataLayer::sortCPlink(string column,bool ascending)
{
    string com = "";
    if(ascending)
    {
        com = "select * from CPlink order by " + column + " asc";
    }
    else
    {
        com = "select * from CPlink order by " + column + " desc";
    }
    vector<CPlink> newList;
    db.open();
    QSqlQuery query(db);
    query.exec(QString::fromStdString(com));

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

vector<string> DataLayer::printCPlink()
{
    vector<string> newList;
    db.open();
    QSqlQuery query(db);
    query.exec("Select p.pname, c.cname from person as p,computer as c, CPlink as cp where cp.personid = p.id and cp.computerid=c.id");

    while(query.next())
    {
        string pName = query.value("pname").toString().toStdString();
        string cName = query.value("cname").toString().toStdString();
        string listString = pName + " is connected to " + cName;
        newList.push_back(listString);
    }
    db.close();
    return newList;
}

vector<CPlink> DataLayer::searchLinkByPerson(string column,string value)
{
    string com = "select cp.id,cp.personid,cp.computerid from CPlink as cp, person as p where cp.personid = p.id and p."+ column+ " like '%"+value+"%'";
    vector<CPlink> newList;
    db.open();
    QSqlQuery query(db);
    query.exec(QString::fromStdString(com));

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

vector<CPlink> DataLayer::searchLinkByComputer(string column,string value)
{
    string com = "select cp.id,cp.personid,cp.computerid from CPlink as cp, computer as c where cp.computerid = c.id and c."+column+" like '%"+value+"%'";
    vector<CPlink> newList;
    db.open();
    QSqlQuery query(db);
    query.exec(QString::fromStdString(com));

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


