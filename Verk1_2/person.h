#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include<list>
using namespace std;
class Person
{
public:
    Person();
    // Default constructor

    Person(string _name,string _gender,int _birthyear,int _deathyear);
    // Constructor that sets name,gender,birthyear and deathyear to input value.

    string getName();
    // Returns the name of a Person instance

    string getGender();
    // Returns the gender of a Person instance

    int getBirthYear();
    // Returns the year of birth of a Person instance

    int getDeathYear();
    //Returns the year of death of a Person instance

    void setName(string _name);
    // Sets the name of a Person instance to input value

    void setGender(string _gender);
    // Sets the gender of a Person instance to input value

    void setBirthYear(int _birthYear);
    // Sets the year of birth of a Person instance to input value

    void setDeathYear(int _deathYear);
    // Sets the year of death of a Person instance to input value

private:
    // Name,gender,year of birth and year of death of a Person instance. Accessed by get/set functions.
    string name;
    string gender;
    int birthYear;
    int deathYear;
};

#endif // PERSON_H
