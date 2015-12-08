#ifndef DOMAINLAYER_H
#define DOMAINLAYER_H
#include "replayer.h"
#include "person.h"
#include "computer.h"
#include "datalayer.h"
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <sstream>
using namespace std;

class DomainLayer
{
public:
    DomainLayer();
    // Default constructor

    vector<Person> sortFromAtoZ();
    // Sorts the names in alphabetical order (A-Z).

    vector<Person> reverse();
    //Sorts the names in reverse alphabetical order (Z-A).

    vector<Person> sortGender();
    //Sorts the list by gender in alphabetical order.

    vector<Person> reverseGender();
    //Sorts the list by gender in reverse alphabetical order.

    vector<Person> sortBirthYear();
    //Sorts the list by year of birth in ascending order.

    vector<Person> sortBirthYearDescending();
    //Sorts the list by year of birth in descending order.

    vector<Person> sortDeathYearDescending();
    //Sorts the list by year of death in descending order.

    vector<Person> sortDeathYear();
    //Sorts the list by year of death in ascending order.

    vector<Person> searchNameFunc(string searchString);
    // Searches for a substring (searchString) in the name of each Person in a list, returns a sublist that has those substrings

    vector<Person> searchGenderFunc(string searchString);
    // Searches for a specific gender in a list og Persons and returns a list with all of the searched for gender.

    vector<Person> searchBirthYearFunc(int searchString);
    // Searches for a specific year of birth in a list of Persons and return a list with all those who have that year of birth.

    vector<Person> searchDeathYearFunc(int searchString);
    // Searches for a specific year of death in a list of Persons and return a list with all those who have that year of death.

    void addPersonToDB(Person newPerson);
    // Add a person to database

    void addComputerToDB(Computer newComputer);
    // Add a person to database

    void addCPlinkToDb(Person p1,Computer c1);
    // Add a Link to database

    vector<Person> loadPerson();
    // Load list of persons

    vector<Computer> loadComputer();
    // Load list of Computers

    vector<CPlink> loadLink();
    // Load a list of Links.

    vector<Computer> sortFromAtoZ_C();
    // Sorts the computer names in alphabetical order (A-Z).

    vector<Computer> reverse_C();
    // Sorts the computer names in reverse alphabetical order (Z-A).

    vector<Computer> sortYearBuild_C();
    // Sorts the computer list by when they were built in ascending order.

    vector<Computer> sortYearBuildReverse_C();
    // Sorts the computer list by when they were built in descending order.

    vector<Computer> sortType_C();
    // Sorts the computer type names in alphabetical order (A-Z).

    vector<Computer> sortTypeReverse_C();
    // Sorts the computer type names in reverse alphabetical order (Z-A).

    vector<Computer> sortMade_C();
    //Sorts the computer list by whether it was made or not in alphabetical order.

    vector<Computer> sortMadeReverse_C();
    //Sorts the comptuer list by whether it was made or not in reverse alphabetical order.

    vector<Computer> searchName_C(string searchString);
    // Searches for a substring (searchString) in the name of each Computer in a list, returns a sublist that has those substrings

    vector<Computer> searchYear_C(int searchString);
    // Searches for a specific year in a list of Computer and returns a list with all computers who were made this year.

    vector<Computer> searchType_C(string searchString);
    // Searches for a substring (searchString) in the type of each Computer in a list, returns a sublist that has those substrings.

    vector<Computer> searchMade_C(string searchString);
    // Searches for a Computer which were made or not, returns a list of Computers which were made or not.

    void deleteFromPerson(Person delPerson);
    // Delete a Person from database.

    void deleteFromComputer(Computer delComputer);
    // Delete a Computer from database.

    void deleteFromCPlink(CPlink delLink);
    // Delete a Link from database(Computer links to Person).

    vector<string> printCPList();
    // Print list of Links

    void createDb();
    // Create a new data base.

    string intToString(int n);
    // Convert int to string

    vector<string> searchLinkByPersonName(string name);
    vector<string> searchLinkByPersonGender(string gender);
    vector<string> searchLinkByPersonBirthyear(int year);
    vector<string> searchLinkByPersonDeathYear(int year);

    vector<string> searchLinkByComputerName(string name);
    vector<string> searchLinkByComputerMade(string made);
    vector<string> searchLinkByComputerType(string type);
    vector<string> searchLinkByComputerYear(int year);

    vector<Person> updatePerson(Person p1);
    vector<Computer> updatePerson(Computer c1);
private:
    DataLayer d1;
};

#endif // DOMAINLAYER_H

