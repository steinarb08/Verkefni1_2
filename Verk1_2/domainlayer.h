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
    vector<Person> sortFromAtoZ(vector<Person> personList);
    //Sorts the names in alphabetical order (A-Z) using bubble sort.

    vector<Person> reverse(vector<Person> personList);
    //Sorts the names in reverse alphabetical order (Z-A) using bubble sort.

    vector<Person> sortGender(vector<Person> personList);
    //Sorts the list by gender in alphabetical order using bubble sort.

    vector<Person> reverseGender(vector<Person> personList);
    //Sorts the list by gender in reverse alphabetical order using bubble sort.

    vector<Person> sortBirthYear(vector<Person> personList);
     //Sorts the list by year of birth in ascending order using bubble sort.

    vector<Person> sortBirthYearDescending(vector<Person> personList);
    //Sorts the list by year of birth in descending order using bubble sort.

    vector<Person> sortDeathYearDescending(vector<Person> personList);
    //Sorts the list by year of death in ascending order using bubble sort.

    vector<Person> sortDeathYear(vector<Person> personList);
    //Sorts the list by year of death in descending order using bubble sort.

    void swap(Person& per1, Person& per2);
    //Swaps two elements.

    vector<Person> searchNameFunc(string searchString,vector<Person> mainList);
    // Searches for a substring (searchString) in the name of each Person in a list, returns a sublist that has those substrings.

    vector<Person> searchGenderFunc(string searchString,vector<Person> mainList);
    // Searches for a specific gender in a list og Persons and returns a list with all of the searched for gender.

    vector<Person> searchBirthYearFunc(int searchString,vector<Person> mainList);
    // Searches for a specific year of birth in a list of Persons and return a list with all those who have that year of birth.

    vector<Person> searchDeathYearFunc(int searchString,vector<Person> mainList);
    // Searches for a specific year of death in a list of Persons and return a list with all those who have that year of death.

    void addPersonToDB(Person newPerson);
    // Add a person to database

    void addComputerToDB(Computer newComputer);
    // Add a person to database

    vector<Person> loadPerson();

    vector<Computer> loadComputer();

    string intToString(int n);
    // Convert int to string
};

#endif // DOMAINLAYER_H

