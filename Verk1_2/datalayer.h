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

    void connect();

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

    void deleteFromDbLink(Person p1, Computer c1);

    Person getPersonFromId(int id);
    // Return a Person from a specific id

    Computer getComputerFromId(int id);
    // Return a Computer from a specific id

    vector<Person> loadDbPersonSort(string column,bool ascending);
    // Sort list of Person by column

    vector<Computer> loadDbComputerSort(string column,bool ascending);
    // Sort list of Computer by column

    vector<Person> searchDbPerson(string column, string value);
    // Search for a Person by a value of a specific column and returns a list of persons that meet the search criteria

    vector<Computer> searchDbComputer(string column, string value);
    // Search for a Computer by a value of a specific column and returns a list of computers that meet the search criteria

    vector<CPlink> sortCPlink(string column,bool ascending);
    // Sort a list of links by a specified column. (1 for ascending,0 for descending)

    vector<Person> updateDbPerson(Person updPerson);
    // Update a person in the database to new values specified in updPerson

    vector<Computer> updateDbComputer(Computer updComputer);
    // Update a computer in the database to new values specified in updComputer

    vector<string> printCPlink();
    // Returns a list of strings that specifies which computers are connected to which persons

    vector<CPlink> searchLinkByPerson(string column,string value);
    // Searches for a link that contains a person that fulfills the specified search criteria. Returns a list of links.

    vector<CPlink> searchLinkByComputer(string column,string value);
    // Searches for a link that contains a computer that fulfills the specified search criteria. Returns a list of links.

    vector<CPlink> loadLinkByComputer(string id);

    vector<CPlink> loadLinkByPerson(string id);

    void deleteFromLinkPersonId(int id);
    // Deletes all links that have the specified person id. (used whenever a person is removed so that links dont contain person that does not exist)

    void deleteFromLinkComputerId(int id);
    // Deletes all links that have the specified computer id. (used whenever a computer is removed so that links dont contain a computer that does not exist)
private:
    QSqlDatabase db;
    // Common database to work with
};


#endif // DATALAYER_H
