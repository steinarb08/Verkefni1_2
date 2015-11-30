#ifndef REPLAYER_H
#define REPLAYER_H

#include <iostream>
#include<vector>
#include<algorithm>
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
    vector<Person> searchNameFunc(string searchString);
    vector<Person> searchGenderFunc(string searchString);
    vector<Person> searchBirthYearFunc(int searchString);
    vector<Person> searchDeathYearFunc(int searchString);

private:
    vector<Person> mainList;
};

#endif // REPLAYER_H
