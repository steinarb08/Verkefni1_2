#ifndef REPLAYER_H
#define REPLAYER_H

#include <iostream>
#include<list>
#include "person.h"
using namespace std;

class RepLayer
{
public:
    RepLayer(list <Person> _mainList);
    void printList(list <Person> _personList);
    void test();
    void startScreen();
    void addToList(list <Person> _personList);

private:
    list<Person> mainList;
};

#endif // REPLAYER_H
