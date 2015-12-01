#include "replayer.h"

// Constructor, needs a vector of Persons to work with as input.
RepLayer::RepLayer(vector<Person> _mainList)
{
    mainList = _mainList;
}

// Prints a list of every Person in a list.
void RepLayer::printList(vector <Person> personList)
{
    cout << "Name - Gender - Year of birth - Year of death" << endl;
    cout << "---------------------------------------------" << endl;
    int size = personList.size();
    for(int i = 0; i < size; i++)
    {
        cout << personList.at(i).getName() << " - ";
        cout << personList.at(i).getGender() << " - ";
        cout << personList.at(i).getBirthYear() << " - ";
        // If not still alive
        if(personList.at(i).getDeathYear() != -1)
        {
            cout << personList.at(i).getDeathYear() << endl;
        }
        else
        {
            cout << "alive"<<endl;
        }
    }
    cout << "---------------------------------------------" << endl;
}

// Prints a list of every Person in a list and numbers them.
void RepLayer::printListNum(vector <Person> personList)
{
    cout << "Nr - Name - Gender - Year of birth - Year of death" << endl;
    cout << "--------------------------------------------------" << endl;
    int size = personList.size();
    for(int i = 0; i < size; i++)
    {
        cout << i;
        cout << ") ";
        cout << personList.at(i).getName() << " - ";
        cout << personList.at(i).getGender() << " - ";
        cout << personList.at(i).getBirthYear() << " - ";
        cout << personList.at(i).getDeathYear() << endl;
    }
    cout << "--------------------------------------------------" << endl;
}

// Used while making the program for testing.
void RepLayer::test()
{
    startScreen();
    //printList(mainList); BARA TIL AÐ TÉKKA Á Á addToList;
}

// Start screen of the program, gives the user options to chose from.
void RepLayer::startScreen()
{
    cout << "Choose one option: " << endl;
    cout << "1) Print list" << endl;
    cout << "2) Add to list" << endl;
    cout << "3) Search " << endl;
    cout << "4) Sort " << endl;
    cout << "5) Remove from list " << endl;
    cout << "6) Quit " << endl;
    int choice;
    string tmpChoice = "";
    cin >> tmpChoice;
    choice = atoi(tmpChoice.c_str());

    switch(choice)
    {
    case 1:
        printList(mainList);
        break;

    case 2:
        addToList();
        break;

    case 3:
        searchList();
        break;

    case 4:
        sortList();
        break;

    case 5:
        removeFromList();
        break;

    case 6:
        exit(0);
        break;


    default:
        cout << "Number not available" << endl;
        startScreen();
        break;
    }
}

// Add a person to the list
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
    newGender = fixName(newGender);
    if(newGender != "Male" && newGender != "Female")
    {
         cout << "Invalid input" << endl;
         cout << "-------------------" << endl;
         addToList();
    }
    else
    {
        cout << "Input year of birth: ";
        string tmpYear = "";
        cin >> tmpYear;
        newBirthYear = atoi(tmpYear.c_str());
        if(newBirthYear > 2015)
        {
            cout << "Invalid birth year" << endl;
            cout << "-------------------" << endl;
            addToList();
        }
        else
        {
            cout << "Input year of death (-1 if still alive): ";
            cin >> tmpYear;
            newDeathYear = atoi(tmpYear.c_str());

            if(newDeathYear == -1)
            {
                newName = fixName(newName);
                Person newP(newName, newGender, newBirthYear, newDeathYear);
                mainList.push_back(newP);
                saveToFile();
            }
            else if(newBirthYear > newDeathYear)
            {
               cout << "Invalid year of death" << endl;
               cout << "-------------------" << endl;
               addToList();
            }
            else
            {
                newName = fixName(newName);
                Person newP(newName, newGender, newBirthYear, newDeathYear);
                mainList.push_back(newP);
                saveToFile();
            }
        }
    }

}

// Loads a list from file by calling to the data layer.
void RepLayer::loadFromFile()
{
    DataLayer d1;
    mainList = d1.load();
}

// Save the current list to file by calling the data layer
void RepLayer::saveToFile()
{
    DataLayer d1;
    d1.save(mainList);
}

// Screen that gives the user several search options and then calls the appropriate DomainLayer search function and prints the results.
void RepLayer::searchList()
{
    int searchChoice;
    cout << "1) Search by name" << endl;
    cout << "2) Search by gender" << endl;
    cout << "3) Search by year of birth" << endl;
    cout << "4) Search by year of death" << endl;

    DomainLayer d1;
    int searchBirthYear, searchDeathYear;
    string searchName, searchGender;
    string tmpChoice = "";
    cin >> tmpChoice;
    searchChoice = atoi(tmpChoice.c_str());
    switch(searchChoice)
    {
    case 1:
        cout << "Type a name: ";
        cin.ignore();
        getline(cin,searchName);
        printList(d1.searchNameFunc(searchName,mainList));
        break;
    case 2:
        cout << "Type a gender: ";
        cin.ignore();
        getline(cin,searchGender);
        searchName = fixName(searchGender);
        printList(d1.searchGenderFunc(searchGender,mainList));
        break;

    case 3:
        cout << "Type a year of birth: ";
        cin.ignore();
        getline(cin,tmpChoice);
        searchBirthYear = atoi(tmpChoice.c_str());
        printList(d1.searchBirthYearFunc(searchBirthYear,mainList));
        break;

    case 4:
        cout << "Type a year of death: ";
        cin.ignore();
        getline(cin,tmpChoice);
        searchDeathYear = atoi(tmpChoice.c_str());
        printList(d1.searchDeathYearFunc(searchDeathYear,mainList));
        break;

     default:
        cout << "Number not available"<< endl;
        searchList();




    }

    // To Be Continued....
}

// Screen that gives the user several sorting options and then calls the appropriate DomainLayer sorting function and prints the results.
void RepLayer::sortList()
{
    int sortChoice;
    DomainLayer d1;
    cout << "Select option: " << endl;
    cout << "1) Sort by name, ascending" << endl;
    cout << "2) Sort by name, decending" << endl;
    cout << "3) Sort by gender, ascending" << endl;
    cout << "4) Sort by gender, decending" << endl;
    cout << "5) Sort by year of birth, ascending" << endl;
    cout << "6) Sort by year of birth, decending" << endl;
    cout << "7) Sort by year of death, ascending" << endl;
    cout << "8) Sort by year of death, decending" << endl;
    string tmpChoice = "";
    cin >> tmpChoice;
    sortChoice = atoi(tmpChoice.c_str());

    switch(sortChoice)
    {
    case 1:
        mainList = d1.sortFromAtoZ(mainList);
        printList(mainList);
        break;

    case 2:
        mainList = d1.reverse(mainList);
        printList(mainList);
        break;

    case 3:
        mainList = d1.sortGender(mainList);
        printList(mainList);
        break;

    case 4:
        mainList = d1.reverseGender(mainList);
        printList(mainList);
        break;

    case 5:
        mainList = d1.sortBirthYear(mainList);
        printList(mainList);
        break;

    case 6:
        mainList = d1.sortBirthYearDescending(mainList);
        printList(mainList);
        break;

    case 7:
        mainList = d1.sortDeathYear(mainList);
        printList(mainList);
        break;

    case 8:
        mainList = d1.sortDeathYearDescending(mainList);
        printList(mainList);
        break;

    default:
        sortList();
        break;


    }

}

// Used to put names in standard format (capital letter at the begining and only at the begining of each name).
string RepLayer::fixName(string name)
{
    string tmpName = name;
    char lastChar = 'A';
    for(unsigned int i =0;i<name.size();i++)
    {
        if(i==0)
        {
            tmpName[0] = toupper(name[0]);
        }
        else
        {
            if(lastChar == ' ')
            {
                tmpName[i] = toupper(name[i]);
            }
            else
            {
                tmpName[i] = tolower(name[i]);
            }

        }
        lastChar = name[i];

    }
    return tmpName;
}

// Prints a list of all Person to the screen and numbers them. Then user can remove an individual from the list.
void RepLayer::removeFromList()
{
    printListNum(mainList);
    cout<< "Choose a nr to remove: ";
    string tmp = "";
    cin>>tmp;
    int choice = atoi(tmp.c_str());
    mainList.erase(mainList.begin() + choice);
    DataLayer d1;
    d1.save(mainList);
}
