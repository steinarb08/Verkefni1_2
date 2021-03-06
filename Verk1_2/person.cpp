#include "person.h"

// Default constructor
Person::Person()
{

}

// Constructor that sets name,gender,birthyear and deathyear to input value.
Person::Person(string _name,string _gender,int _birthyear,int _deathyear)
{
    name = _name;
    gender = _gender;
    birthYear = _birthyear;
    deathYear = _deathyear;
}

// Constructor that sets name,gender,birthyear,deathyear and id to input value.
Person::Person(string _name,string _gender,int _birthyear,int _deathyear,int _id)
{
    name = _name;
    gender = _gender;
    birthYear = _birthyear;
    deathYear = _deathyear;
    id = _id;
}


// Returns the name of a Person instance
string Person::getName()
{
    return name;
}

// Returns the gender of a Person instance
string Person::getGender()
{
    return gender;
}

// Returns the year of birth of a Person instance
int Person::getBirthYear()
{
    return birthYear;
}

//Returns the year of death of a Person instance
int Person::getDeathYear()
{
    return deathYear;
}

// Returns the id of a Person instance
int Person::getId()
{
    return id;
}

// Sets the name of a Person instance to input value
void Person::setName(string _name)
{
    name = _name;
}

// Sets the gender of a Person instance to input value
void Person::setGender(string _gender)
{
    gender = _gender;
}

// Sets the year of birth of a Person instance to input value
void Person::setBirthYear(int _birthYear)
{
    birthYear = _birthYear;
}

// Sets the year of death of a Person instance to input value
void Person::setDeathYear(int _deathYear)
{
    deathYear = _deathYear;
}

// Sets the id of a Person instance to input value
void Person::setId(int _id)
{
    id = _id;
}
