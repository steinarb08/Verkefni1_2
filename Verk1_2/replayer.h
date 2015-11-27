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
    void addToList();
    void loadFromFile();
    void saveToFile();
    void searchList();
    void sortList();

private:
    list<Person> mainList;
};

#endif // REPLAYER_H
