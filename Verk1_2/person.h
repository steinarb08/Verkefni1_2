#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include<list>
using namespace std;
class Person
{
public:
    Person();
    Person(string _name,string _gender,int _birthyear,int _deathyear);
    string getName();
    string getGender();
    int getBirthYear();
    int getDeathYear();
    void setName(string _name);
    void setGender(string _gender);
    void setBirthYear(int _birthYear);
    void setDeathYear(int _deathYear);

private:
    string name;
    string gender;
    int birthYear;
    int deathYear;
};

#endif // PERSON_H
