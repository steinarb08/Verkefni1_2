#include "person.h"

Person::Person()
{

}

Person::Person(string _name,string _gender,int _birthyear,int _deathyear)
{
    name = _name;
    gender = _gender;
    birthYear = _birthyear;
    deathYear = _deathyear;
}



string Person::getName()
{
    return name;
}

string Person::getGender()
{
    return gender;
}

int Person::getBirthYear()
{
    return birthYear;
}

int Person::getDeathYear()
{
    return deathYear;
}

void Person::setName(string _name)
{
    name = _name;
}

void Person::setGender(string _gender)
{
    gender = _gender;
}

void Person::setBirthYear(int _birthYear)
{
    birthYear = _birthYear;
}

void Person::setDeathYear(int _deathYear)
{
    deathYear = _deathYear;
}
