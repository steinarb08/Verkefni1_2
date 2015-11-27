#include "replayer.h"

RepLayer::RepLayer(list<Person> _mainList)
{
    mainList = _mainList;
}

void RepLayer::printList(list <Person> personList)
{
    cout << "Name - Gender - Year of birth - Year of death" << endl;
    int size = personList.size();
    for(int i = 0; i < size; i++)
    {
        cout << personList.front().getName() << " - " << personList.front().getGender() << " - ";
        cout << personList.front().getBirthYear() << " - " << personList.front().getDeathYear() << endl;
        personList.pop_front();
    }
}

void RepLayer::test()
{
    startScreen();
}

void RepLayer::startScreen()
{
    cout << "Choose one option: " << endl;
    cout << "1) Print list" << endl;
    cout << "2) Add to list" << endl;
    cout << "3) Load from file" << endl;
    cout << "4) Save to file" << endl;
    cout << "5) Search " << endl;
    cout << "6) Sort " << endl;
    cout << "7) Quit " << endl;

    int choice;

    cin >> choice;

    switch(choice)
    {
    case 1:
        printList(mainList);
        break;

    case 2:
        break;

    case 3:
        break;

    case 4:
        break;

    case 5:
        break;

    case 6:
        break;

    case 7:
        exit(0);
        break;


    default:
        cout << "Number not available" << endl;
        startScreen();
        break;
    }
}

void addToList(list <Person> personList)
{
    // Create interface that allows you to add to the list.
}
