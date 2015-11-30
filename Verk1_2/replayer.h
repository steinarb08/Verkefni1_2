#ifndef REPLAYER_H
#define REPLAYER_H

#include <iostream>
#include<vector>
#include "person.h"

using namespace std;

class RepLayer
{
public:
    RepLayer(vector <Person> _mainList);
    void printList(vector <Person> _personList);
    void test();
    void startScreen();
    void addToList();
    void loadFromFile();
    void saveToFile();
    void searchList();
    void sortList();

private:
    vector<Person> mainList;
};

#endif // REPLAYER_H
