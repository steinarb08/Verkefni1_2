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
    vector<Person> reverse(vector<Person> personList);
    void swap(Person& per1, Person& per2);
};

#endif // DOMAINLAYER_H
