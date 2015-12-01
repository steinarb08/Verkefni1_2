#ifndef REPLAYER_H
#define REPLAYER_H

#include <iostream>
#include<vector>
#include<algorithm>
#include "person.h"
#include <datalayer.h>
#include <domainlayer.h>

using namespace std;

class RepLayer
{
public:
    RepLayer(vector <Person> _mainList);
    void printList(vector <Person> _personList);
    void printList(vector <Person> _personList,bool b);
    void test();
    void startScreen();
    void addToList();
    void loadFromFile();
    void saveToFile();
    void searchList();
    void sortList();
    void removeFromList();
    string fixName(string name);


private:
    vector<Person> mainList;
};

#endif // REPLAYER_H
