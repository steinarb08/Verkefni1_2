#ifndef REPLAYER_H
#define REPLAYER_H

#include <iostream>
#include<vector>
#include<algorithm>
#include "person.h"
#include <datalayer.h>
#include <domainlayer.h>
#include "computer.h"

using namespace std;

class RepLayer
{
public:
    RepLayer(vector <Person> _mainList, vector<Computer> _mainCompList);
    // Constructor, needs a vector of Persons to work with as input.

    //RepLayer(vector <Computer> _mainCompList);
    // Constructor, needs a vector of Computer to work with as input.

    void printList(vector <Person> _personList);
    // Prints a list of every Person in a list.

    void printListNum(vector <Person> _personList);
    // Prints a list of every Person in a list and numbers them.

    void test();
    // Used while making the program for testing.

    void startScreen();
    // Start screen of the program for persons, gives the user options to chose from.

    void addToList();
    // Add a person to the list

    void loadFromFile();
    // Loads a list from file by calling to the data layer.

    void saveToFile();
    // Save the current list to file by calling the data layer

    void searchList();
    // Screen that gives the user several search options and then calls the appropriate DomainLayer search function and prints the results.

    void sortList();
    // Screen that gives the user several sorting options and then calls the appropriate DomainLayer sorting function and prints the results.

    void removeFromList();
    // Prints a list of all Person to the screen and numbers them. Then user can remove an individual from the list.

    string fixName(string name);
    // Used to put names in standard format (capital letter at the begining and only at the begining of each name).

    void firstStartScreen();
    // Start screen of the program, gives the user options to chose from.

    void startScreenComputer();
    // Start screen of the program for computers, gives the user options to chose from.

    void addToListComp();
    // Add computers to list

private:
    // List of Persons to work with.
    vector<Person> mainList;
    //List of Computer to work with.
    vector<Computer> mainCompList;
};

#endif // REPLAYER_H
