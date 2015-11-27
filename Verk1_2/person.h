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


private:
    string name;
    string gender;
    int birthYear;
    int deathYear;
};

#endif // PERSON_H
