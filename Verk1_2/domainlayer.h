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
    vector<Person> sortFromAtoZ();
    //Sorts the names in alphabetical order (A-Z) using bubble sort.

    vector<Person> reverse();
    //Sorts the names in reverse alphabetical order (Z-A) using bubble sort.

    vector<Person> sortGender();
    //Sorts the list by gender in alphabetical order using bubble sort.

    vector<Person> reverseGender();
    //Sorts the list by gender in reverse alphabetical order using bubble sort.

    vector<Person> sortBirthYear();
     //Sorts the list by year of birth in ascending order using bubble sort.

    vector<Person> sortBirthYearDescending();
    //Sorts the list by year of birth in descending order using bubble sort.

    vector<Person> sortDeathYearDescending();
    //Sorts the list by year of death in ascending order using bubble sort.

    vector<Person> sortDeathYear();
    //Sorts the list by year of death in descending order using bubble sort.

    void swap(Person& per1, Person& per2);
    //Swaps two elements.

    vector<Person> searchNameFunc(string searchString);
    // Searches for a substring (searchString) in the name of each Person in a list, returns a sublist that has those substrings.

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

    vector<Person> loadPerson();

    vector<Computer> loadComputer();

    vector<CPlink> loadLink();

    vector<Computer> sortFromAtoZ_C();

    vector<Computer> reverse_C();

    vector<Computer> sortYearBuild_C();

    vector<Computer> sortYearBuildReverse_C();

    vector<Computer> sortType_C();

    vector<Computer> sortTypeReverse_C();

    vector<Computer> sortMade_C();

    vector<Computer> sortMadeReverse_C();

    vector<Computer> searchName_C(string searchString);

    vector<Computer> searchYear_C(int searchString);

    vector<Computer> searchType_C(string searchString);

    vector<Computer> searchMade_C(string searchString);

    void deleteFromPerson(Person delPerson);

    void deleteFromComputer(Computer delComputer);

    void deleteFromCPlink(CPlink delLink);

    vector<string> printCPList();

    void createDb();

    string intToString(int n);
    // Convert int to string
private:
    DataLayer d1;
};

#endif // DOMAINLAYER_H

