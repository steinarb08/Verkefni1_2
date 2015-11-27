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
        cout << personList.front().getName() << " - ";
        cout << personList.front().getGender() << " - ";
        cout << personList.front().getBirthYear() << " - ";
        cout << personList.front().getDeathYear() << endl;
        personList.pop_front();
    }
}

void RepLayer::test()
{
    startScreen();
    //printList(mainList); BARA TIL AÐ TÉKKA Á Á addToList;
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
        addToList();
        break;

    case 3:
        loadFromFile();
        break;

    case 4:
        saveToFile();
        break;

    case 5:
        searchList();
        break;

    case 6:
        sortList();
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

void RepLayer::addToList()
{
    string newName, newGender;
    int newBirthYear, newDeathYear;
    cout << "Creating new person" << endl;
    cout << "Input name: ";
    cin >> newName;
    cout << "Input gender: ";
    cin >> newGender;
    cout << "Input year of birth: ";
    cin >> newBirthYear;
    cout << "Input year of death: ";
    cin >> newDeathYear;

    Person newP(newName, newGender, newBirthYear, newDeathYear);
    mainList.push_back(newP);

}

void RepLayer::searchList()
{
    string searchString;
    cout << "Search: ";
    cin >> searchString;

    // To Be Continued....
}

void RepLayer::sortList()
{
    int sortChoice;

    cout << "Select option: " << endl;
    cout << "1) Sort by name, ascending" << endl;
    cout << "2) Sort by name, decending" << endl;
    cout << "3) Sort by gender, ascending" << endl;
    cout << "4) Sort by gender, decending" << endl;
    cout << "5) Sort by year of birth, ascending" << endl;
    cout << "6) Sort by year of birth, decending" << endl;
    cout << "7) Sort by year of death, ascending" << endl;
    cout << "8) Sort by year of death, decending" << endl;
    cin >> sortChoice;

    switch(sortChoice)
    {
    case 1:
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
        break;

    case 8:
        break;

    default:
        exit(0);
        break;


    }

}

void RepLayer::loadFromFile()
{
    cout << "Load from file";
}

void RepLayer::saveToFile()
{
    cout << "Save to file";
}







