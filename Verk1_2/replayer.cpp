#include "replayer.h"

RepLayer::RepLayer(vector<Person> _mainList)
{
    mainList = _mainList;
}

void RepLayer::printList(vector <Person> personList)
{
    cout << "Name - Gender - Year of birth - Year of death" << endl;
    int size = personList.size();
    for(int i = 0; i < size; i++)
    {
        cout << personList.at(i).getName() << " - ";
        cout << personList.at(i).getGender() << " - ";
        cout << personList.at(i).getBirthYear() << " - ";
        cout << personList.at(i).getDeathYear() << endl;
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
    cin.ignore();
    getline(cin,newName);

    cout << "Input gender: ";
    cin >> newGender;
    newGender[0] = toupper(newGender[0]);

    if(newGender != "Male" && newGender != "Female")
    {    cout << newGender;
         cout << "Invalid input" << endl;
         addToList();
    }
    else
    {
        cout << "Input year of birth: ";
        cin >> newBirthYear;
        cout << "Input year of death: ";
        cin >> newDeathYear;

        if(newBirthYear > newDeathYear)
        {
           cout << "Invalid year of death" << endl;
           addToList();
        }
        else
        {
            newName[0] = toupper(newName[0]);
            Person newP(newName, newGender, newBirthYear, newDeathYear);
            mainList.push_back(newP);
            saveToFile();
        }
    }

}

void RepLayer::loadFromFile()
{
    DataLayer d1;
    mainList = d1.load();
}

void RepLayer::saveToFile()
{
    DataLayer d1;
    d1.save(mainList);
}

void RepLayer::searchList()
{
    int searchChoice;
    cout << "1) Search by name" << endl;
    cout << "2) Search by gender" << endl;
    cout << "3) Search by year of birth" << endl;
    cout << "4) Search by year of death" << endl;

    int searchBirthYear, searchDeathYear;
    string searchName, searchGender;
    cin >> searchChoice;
    switch(searchChoice)
    {
    case 1:
        cout << "Type a name: ";
        cin >> searchName;
        printList(searchNameFunc(searchName));
        break;
    case 2:
        cout << "Type a gender: ";
        cin >> searchGender;
        printList(searchGenderFunc(searchGender));
        break;

    case 3:
        cout << "Type a year of birth: ";
        cin >> searchBirthYear;
        printList(searchBirthYearFunc(searchBirthYear));
        break;

    case 4:
        cout << "Type a year of death: ";
        cin >> searchDeathYear;
        printList(searchDeathYearFunc(searchDeathYear));
        break;

     default:
        cout << "Number not available"<< endl;
        searchList();




    }

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

vector<Person> RepLayer::searchNameFunc(string searchString)
{
    vector<Person> newVector;
    int sizeOfList = mainList.size();
    for(int i = 0; i < sizeOfList; i++)
    {
         int it;
         it = mainList.at(i).getName().find(searchString);
         if(it != -1)
         {
             newVector.push_back(mainList.at(i));
         }


    }
    return newVector;
}

vector<Person> RepLayer::searchGenderFunc(string searchString)
{
    vector<Person> newVector;
    int sizeOfList = mainList.size();
    for(int i = 0; i < sizeOfList; i++)
    {
         int it;
         it = mainList.at(i).getGender().find(searchString);
         if(it != -1)
         {
             newVector.push_back(mainList.at(i));
         }


    }
    return newVector;
}

vector<Person> RepLayer::searchBirthYearFunc(int searchString)
{
    vector<Person> newVector;
    int sizeOfList = mainList.size();
    for(int i = 0; i < sizeOfList; i++)
    {
         if(mainList.at(i).getBirthYear() == searchString)
         {
             newVector.push_back(mainList.at(i));
         }


    }
    return newVector;
}

vector<Person> RepLayer::searchDeathYearFunc(int searchString)
{
    vector<Person> newVector;
    int sizeOfList = mainList.size();
    for(int i = 0; i < sizeOfList; i++)
    {
         if(mainList.at(i).getDeathYear() == searchString)
         {
             newVector.push_back(mainList.at(i));
         }

    }
    return newVector;
}



