#ifndef REPLAYER_H
#define REPLAYER_H
#include <domainlayer.h>
#include <iostream>
#include<vector>
#include<algorithm>
#include "person.h"
#include <datalayer.h>
#include "computer.h"

using namespace std;

class RepLayer
{
public:
    RepLayer(vector <Person> _mainList, vector<Computer> _mainCompList);
    // Constructor, needs a vector of Persons to work with as input.

    void printList(vector <Person> _personList);
    // Prints a list of every Person in a list.

    void printListNum(vector<Person> _personList);
    // Prints a list of every Person in a list and numbers them.

    void startScreen();
    // Start screen of the program for persons, gives the user options to choose from.

    void addToList();
    // Adds a person to the list.

    void loadFromFile();
    // Loads a list from file by calling to the data layer.

    void searchList();
    // Screen that gives the user several search options and then calls
    // the appropriate DomainLayer search function and prints the results.

    void sortList();
    // Screen that gives the user several sorting options and then calls
    // the appropriate DomainLayer sorting function and prints the results.

    void removeFromList();
    // Prints a list of all Person to the screen and numbers them. Then user can remove an individual from the list.

    string fixName(string name);
    // Used to put names in standard format (capital letter at the begining and only at the begining of each name).

    void firstStartScreen();
    // Start screen of the program, gives the user options to choose from.

    void startScreenComputer();
    // Start screen of the program for computers, gives the user options to choose from.

    void startScreenCpLink();
    // Start screen of the program for CPlinks, gives the user options to choose from.

    void addToListCpLink();
    // Adds CpLinks to list

    void addToListComp();
    // Add computers to list

    void searchComp();
    // Screen that gives the user several search options and then calls
    // the appropriate DomainLayer search function and prints the results.

    void sortListComp();
    // Sorts and prints out list with computer

    void printListComp(vector<Computer> computerList);
    // Prints a list of every computer.

    void printListCPlink();
    // Prints a list of every computer.

    void printListNumComp(vector<Computer> computerList);
    // Prints a list of every Computer in a list and numbers them.

    void removeComp();
    // Remove from computer list

    void removeLinks();
    // Removes connections between computer and persons

    void printListCPlinkNum();
    // Prints nr in front of every name for user to choose from.

    void searchCPLink();
    // Search for link between persons and computer

    void  searchCompLink();
    // Search for computers in link

    void searchListLink();
    // Search for persons in link

    void updatePersonScreen();
    // Screen for updating person.

    void printSinglePerson(vector<Person> personList, int choice);
    //

    void updateComputerScreen();
    //Screen for updating computer.

    void printSingleComp(vector<Computer> compList, int choice);
    //

private:
    // List of Persons to work with.
    vector<Person> mainList;
    //List of Computer to work with.
    vector<Computer> mainCompList;
    //List of CPlinks to work with.
    vector<CPlink> CPlinkList;
};

#endif // REPLAYER_H
