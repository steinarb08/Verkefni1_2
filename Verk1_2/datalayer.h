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

    vector<Person> loadDbPersonSort(string column,bool ascending);
    // Sort list of Person by column

    vector<Computer> loadDbComputerSort(string column,bool ascending);
    // Sort list of Computer by column

    vector<Person> searchDbPerson(string column, string value);

    vector<Computer> searchDbComputer(string column, string value);

    vector<CPlink> sortCPlink(string column,bool ascending);

    vector<Person> updateDbPerson(Person updPerson);

    vector<Computer> updateDbComputer(Computer updComputer);

    vector<string> printCPlink();

    vector<CPlink> searchLinkByPerson(string column,string value);

    vector<CPlink> searchLinkByComputer(string column,string value);


private:
    QSqlDatabase db;
};


#endif // DATALAYER_H
