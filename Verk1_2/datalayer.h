#ifndef DATALAYER_H
#include <QtSql>
#include <stdio.h>
#include <person.h>
#include <computer.h>
#include <cplink.h>
#include <vector>
#define DATALAYER_H
using namespace std;

class DataLayer
{
public:
    DataLayer();
    // Default constructor

    DataLayer(string dbName);
    // Constructor with custom database name

    void createTables();
    // Creates the tables needed for our database

    void dropTables();
    // Drops all our tables from our database

    void insertToDbPerson(Person newPerson);
    // Inserts a Person to database

    void insertToDbComputer(Computer newComputer);
    // Inserts a computer to database

    void insertToDbCPLink(Computer newComputer,Person newPerson);
    // Insert a new connection between scientist and computer to database

    vector<Person> loadDbPerson();
    // Loads all Person from database on puts them into vector.

    vector<Computer> loadDbComputer();
    // Loads all computers from database and puts them into vector

    vector<CPlink> loadDbCPlink();
    // Loads all links from database and returns a vector

    void deleteFromDbPerson(Person delPerson);
    // Deletes selectec person from database

    void deleteFromDbComputer(Computer delComputer);
    // Deletes a computer from database

    void deleteFromDbLink(CPlink delLink);
    // Deletes a link from database

    Person getPersonFromId(int id);
    // Return a Person from a specific id

    Computer getComputerFromId(int id);
    // Return a Computer from a specific id

private:
    QSqlDatabase db;
};


#endif // DATALAYER_H
