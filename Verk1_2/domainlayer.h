#ifndef DOMAINLAYER_H
#define DOMAINLAYER_H
#include "replayer.h"
#include "person.h"
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
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
};

#endif // DOMAINLAYER_H
