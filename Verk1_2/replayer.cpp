#include "replayer.h"

DomainLayer d1;


// Constructor, needs a vector of Persons to work with as input.
RepLayer::RepLayer(vector<Person> _mainList, vector<Computer> _mainCompList)
{
    mainList = _mainList;
    mainCompList = _mainCompList;
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
    // Create test data

    Person p1("john","male",1693,1750);
    Person p2("Ivan","male",1723,1800);
    Person p3("Steve","male",1980,-1);
    Person p4("Charles","male",1842,1903);
    Person p5("Rachel","female",1693,1762);
    Person p6("Hilda","female",1743,1820);
    Person p7("Catherin","female",1920,1999);

    Computer c1("Super1",1923,"mechanical","yes");
    Computer c2("Super2",1930,"mechanical","yes");
    Computer c3("BetterSuper1",1931,"electrical","yes");
    Computer c4("Super3",1935,"mechanical","yes");
    Computer c5("MuchBetterSuper1",1938,"mechanical","yes");

    vector<Person> testList;
    testList.push_back(p1);
    testList.push_back(p2);
    testList.push_back(p3);
    testList.push_back(p4);
    testList.push_back(p5);
    testList.push_back(p6);
    testList.push_back(p7);

    vector<Computer> testComputerList;

    testComputerList.push_back(c1);
    testComputerList.push_back(c2);
    testComputerList.push_back(c3);
    testComputerList.push_back(c4);
    testComputerList.push_back(c5);


    // Apply test data to our lists
    mainList = testList;
    mainCompList = testComputerList;

}

// Start screen of the program, gives the user options to choorse from.
void RepLayer::startScreen()
{
    cout << "Choose one option: " << endl;
    cout << "1) Print list" << endl;
    cout << "2) Add to list" << endl;
    cout << "3) Search " << endl;
    cout << "4) Remove from list " << endl;
    cout << "5) Quit " << endl;
    int choice;
    string tmpChoice = "";
    cin >> tmpChoice;
    choice = atoi(tmpChoice.c_str());

    switch(choice)
    {
        case 1:
            sortList();
            break;

        case 2:
            addToList();
            break;

        case 3:
            searchList();
            break;

        case 4:
            removeFromList();
            break;

        case 5:
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
    int genderChoice;

    cout << "Creating new person" << endl;
    cout << "Input name: ";
    cin.ignore();
    getline(cin,newName);

    cout << "Input Gender(0 for female and 1 for male):";
    string tmpGender = "";
    cin >> tmpGender;
    genderChoice = atoi(tmpGender.c_str());

    if(genderChoice == 0)
    {
        newGender = "Female";
    }
    else if(genderChoice == 1)
    {
        newGender = "Male";
    }
    else
    {
        cout << "Invalid input" << endl;
        cout << "-------------------" << endl;
        addToList();
    }

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
            d1.addPersonToDB(newP);
            saveToFile();
            loadFromFile();
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
            d1.addPersonToDB(newP);
            saveToFile();// delete these
        }

        cout << newName << " has been added!" << endl;
        cout << endl;
    }
}

// Loads a list from file by calling to the data layer.
void RepLayer::loadFromFile()
{
    mainList = d1.loadPerson();
    mainCompList = d1.loadComputer();
    CPlinkList = d1.loadLink();
}

// Save the current list to file by calling the data layer
void RepLayer::saveToFile()
{
}

// Screen that gives the user several search options and then calls
// the appropriate DomainLayer search function and prints the results.
void RepLayer::searchList()
{
    int searchChoice;
    cout << "Choose one option: " << endl;
    cout << "1) Search by name" << endl;
    cout << "2) Search by gender" << endl;
    cout << "3) Search by year of birth" << endl;
    cout << "4) Search by year of death" << endl;

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
            printList(d1.searchNameFunc(searchName));
            break;
        case 2:
            cout << "Type a gender: ";
            cin.ignore();
            getline(cin,searchGender);
            printList(d1.searchGenderFunc(searchGender));
            break;

        case 3:
            cout << "Type a year of birth: ";
            cin.ignore();
            getline(cin,tmpChoice);
            searchBirthYear = atoi(tmpChoice.c_str());
            printList(d1.searchBirthYearFunc(searchBirthYear));
            break;

        case 4:
            cout << "Type a year of death: ";
            cin.ignore();
            getline(cin,tmpChoice);
            searchDeathYear = atoi(tmpChoice.c_str());
            printList(d1.searchDeathYearFunc(searchDeathYear));
            break;

        default:
            cout << "Number not available"<< endl;
            searchList();
    }

    // To Be Continued....
}

// Screen that gives the user several sorting options and then calls
// the appropriate DomainLayer sorting function and prints the results.
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
    string tmpChoice = "";
    cin >> tmpChoice;
    sortChoice = atoi(tmpChoice.c_str());

    switch(sortChoice)
    {
        case 1:
            mainList = d1.sortFromAtoZ();
            printList(mainList);
            break;

        case 2:
            mainList = d1.reverse();
            printList(mainList);
            break;

        case 3:
            mainList = d1.sortGender();
            printList(mainList);
            break;

        case 4:
            mainList = d1.reverseGender();
            printList(mainList);
            break;

        case 5:
            mainList = d1.sortBirthYear();
            printList(mainList);
            break;

        case 6:
            mainList = d1.sortBirthYearDescending();
            printList(mainList);
            break;

        case 7:
            mainList = d1.sortDeathYear();
            printList(mainList);
            break;

        case 8:
            mainList = d1.sortDeathYearDescending();
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
    d1.deleteFromPerson(mainList.at(choice));
    loadFromFile();
}

// Start screen of the program, gives the user options to choose from.
void RepLayer::firstStartScreen()
{
    loadFromFile();
    cout << "Choose one option" << endl;
    cout << "1) Persons" << endl;
    cout << "2) Computer" << endl;
    cout << "3) Links" << endl;
    cout << "4) Reset Database" <<endl;
    cout << "0) Exit" << endl;

    int choice;
    string tmpChoice = "";
    cin >> tmpChoice;
    choice = atoi(tmpChoice.c_str());

    switch(choice)
    {
        case 1:
            startScreen();
            break;

        case 2:
            startScreenComputer();
            break;

        case 3:
            startScreenCpLink();
            break;
        case 4:
            d1.createDb();
            break;
            //TAKE OUT BEFORE HANDIN
        case 0:
            exit(0);
            break;
    }
}

// Start screen of the program for computers, gives the user options to choose from.
void RepLayer::startScreenComputer()
{
    cout << "Choose one option" << endl;
    cout << "1) Print list" << endl;
    cout << "2) Add to list" << endl;
    cout << "3) Search" << endl;
    cout << "4) Remove from list" << endl;
    cout << "5) Exit" << endl;
    int choice;
    string tmpChoice = "";
    cin >> tmpChoice;
    choice = atoi(tmpChoice.c_str());

    switch(choice)
    {
        case 1:
            sortListComp();
            //Sort og svo Print list;
            break;

        case 2:
            addToListComp();
            break;

        case 3:
            searchComp();
            break;

        case 4:
            removeComp();
            // Remove..
            break;

        case 5:
            exit(0);
            break;
    }
}

// Add computers to list
void RepLayer::addToListComp()
{
    string newComp, newType, newBuiltComp ;
    int  newBuiltYear;
    cout << "Creating new computer" << endl;
    cout << "Input computer name: ";
    cin.ignore();
    getline(cin,newComp);

    cout << "Input building year: ";
    string tmpBuiltYear = "";
    cin >> tmpBuiltYear;
    newBuiltYear = atoi(tmpBuiltYear.c_str());
    if(newBuiltYear < 0 && newBuiltYear > 2015){
        cout << "Invalid year of built!" << endl;
        cout << "-------------------" << endl;
        addToList();
    }

    cout << "Input a type: ";
    cin.ignore();
    getline(cin,newType);

    cout << "Was the computer built(0 for No and 1 for Yes): ";
    string tmpBuiltComp = "";
    cin >> tmpBuiltComp;
    int coicheBuiltComp = atoi(tmpBuiltComp.c_str());

    if(coicheBuiltComp != 0 && coicheBuiltComp != 1){
        cout << "Invalid input!" << endl;
        cout << "-------------------" << endl;
        addToList();
    }
    if(coicheBuiltComp == 1){
        newBuiltComp = "Yes";
    }
    if(coicheBuiltComp == 0){
        newBuiltComp = "No";
    }

    newComp = fixName(newComp);
    newType = fixName(newType);

    cout << newComp << " has been added!" << endl;
    cout << endl;

    Computer newC(newComp, newBuiltYear, newType, newBuiltComp);
    d1.addComputerToDB(newC);
    loadFromFile();
    //mainCompList.push_back(newC);

}

// Screen that gives the user several search options and then calls
// the appropriate DomainLayer search function and prints the results.
void RepLayer::searchComp()
{
    cout << "Choose one option" << endl;
    cout << "1) Search computer" << endl;
    cout << "2) Search build year" << endl;
    cout << "3) Search a type of computer" << endl;
    cout << "4) Exit" << endl;
    string tmpChoice = "";
    cin >> tmpChoice;
    int searchChoice = atoi(tmpChoice.c_str());
    int searchInteger;
    switch(searchChoice)
    {
        case 1:
            cout << "Type a computer: ";
            cin.ignore();
            getline(cin,tmpChoice);
            printListComp(d1.searchName_C(tmpChoice));
            break;
        case 2:
            cout << "Type a build year: ";
            cin.ignore();
            getline(cin,tmpChoice);
            searchInteger = atoi(tmpChoice.c_str());
            printListComp(d1.searchYear_C(searchInteger));
            break;
        case 3:
            cout << "Type a build year: ";
            cin.ignore();
            getline(cin,tmpChoice);
            printListComp(d1.searchType_C(tmpChoice));
            break;

        case 4:
            exit(0);
            break;

        default:
            searchComp();
            break;
    }
}

// Sorts and prints out list with computer
void RepLayer::sortListComp()
{
    int sortChoice;
    cout << "Select option: " << endl;
    cout << "1) Sort by computer, ascending" << endl;
    cout << "2) Sort by computer, decending" << endl;
    cout << "3) Sort by build year, ascending" << endl;
    cout << "4) Sort by build year, decending" << endl;
    cout << "5) Sort by type, ascending" << endl;
    cout << "6) Sort by type, decending" << endl;

    string tmpChoice = "";
    cin >> tmpChoice;
    sortChoice = atoi(tmpChoice.c_str());

    switch(sortChoice)
    {
        case 1:
            mainCompList = d1.sortFromAtoZ_C();
            printListComp(mainCompList);
            break;

        case 2:
            mainCompList = d1.reverse_C();
            printListComp(mainCompList);
            break;

        case 3:
            mainCompList = d1.sortYearBuild_C();
            printListComp(mainCompList);
            break;

        case 4:
            mainCompList = d1.sortYearBuildReverse_C();
            printListComp(mainCompList);
            break;

        case 5:
            mainCompList = d1.sortType_C();
            printListComp(mainCompList);
            break;

        case 6:
            mainCompList = d1.sortTypeReverse_C();
            printListComp(mainCompList);
            break;

        default:
            sortListComp();
            break;
    }
}

// Prints a list of every computer.
void RepLayer::printListComp(vector<Computer> computerList)
{
    cout << "Computer - Build Year - Type - Was it Built" << endl;
    cout << "---------------------------------------------" << endl;
    int size = computerList.size();
    for(int i = 0; i < size; i++)
    {
        cout << computerList.at(i).getName() << " - ";
        cout << computerList.at(i).getBuiltYear() << " - ";
        cout << computerList.at(i).getType() << " - ";
        cout << computerList.at(i).getBuiltComputer() << endl;

    }
    cout << "---------------------------------------------" << endl;
}

// Prints a list of every Computer in a list and numbers them.
void RepLayer::printListNumComp(vector<Computer> computerList)
{
    cout << "Nr - Computer - Build Year - Type - Was it Built" << endl;
    cout << "--------------------------------------------------" << endl;
    int size = computerList.size();
    for(int i = 0; i < size; i++)
    {
        cout << i;
        cout << ") ";
        cout << computerList.at(i).getName() << " - ";
        cout << computerList.at(i).getBuiltYear() << " - ";
        cout << computerList.at(i).getType() << " - ";
        cout << computerList.at(i).getBuiltComputer() << endl;
    }
    cout << "--------------------------------------------------" << endl;
}

// Remove nr list of computer
void RepLayer::removeComp()
{
    printListNumComp(mainCompList);
    cout<< "Choose a nr to remove: ";
    string tmp = "";
    cin >> tmp;
    int choice = atoi(tmp.c_str());
    d1.deleteFromComputer(mainCompList.at(choice));
    loadFromFile();
}

// Prints a list of every computer.
void RepLayer::printListCPlink()
{
    cout << "Links between Computers and Scientists" << endl;
    cout << "--------------------------------------------------" << endl;

    vector<string> CPlist = d1.printCPList();

    for (unsigned int i = 0; i < CPlist.size(); i++) {
        cout << CPlist.at(i) << endl;
    }
    cout << "--------------------------------------------------" << endl;
}

// Adds CpLinks to list
void RepLayer::addToListCpLink(){
    printListNum(mainList);
    int personChoice;

    cout << "Choose a person to link with: ";
    cin >> personChoice;
    Person p1 = mainList.at(personChoice);

    printListNumComp(mainCompList);
    int computerChoice;

    cout << "Choose a computer to link with: ";
    cin >> computerChoice;

    Computer c1 = mainCompList.at(computerChoice);

    d1.addCPlinkToDb(p1,c1);
    CPlinkList = d1.loadLink();
}

// Start screen of the program for CPlinks, gives the user options to choose from.
void RepLayer::startScreenCpLink()
{
    cout << "Choose one option" << endl;
    cout << "1) Print list" << endl;
    cout << "2) Add to list" << endl;
    cout << "3) Remove from list" << endl;
    cout << "4) Search link" << endl;
    cout << "5) Exit" << endl;
    int choice;
    string tmpChoice = "";
    cin >> tmpChoice;
    choice = atoi(tmpChoice.c_str());

    switch(choice)
    {
        case 1:
            printListCPlink();
            break;

        case 2:
            addToListCpLink();
            break;

        case 3:
            removeLinks();
            break;

        case 4:
            searchCPLink();
            break;

        case 5:
            exit(0);
            break;
    }
}

void RepLayer::removeLinks()
{
    printListCPlinkNum();
    cout<< "Choose a nr to remove: ";
    string tmp = "";
    cin >> tmp;
    int choice = atoi(tmp.c_str());
    d1.deleteFromCPlink(CPlinkList.at(choice));
    loadFromFile();

}

void RepLayer::printListCPlinkNum()
{
    cout << "Choose one number to remove" << endl;
    cout << "---------------------------" << endl;
    vector<string> CPlist = d1.printCPList();

    for (unsigned int i = 0; i < CPlist.size(); i++) {
        cout << i;
        cout << ") ";
        cout << CPlist.at(i) << endl;
    }
}

void RepLayer::searchCPLink()
{
    cout << "Choose one search option" << endl;
    cout << "------------------------" << endl;
    cout << "1) Search by computers" << endl;
    cout << "2) Search by persons" << endl;
    cout << "3) Exit " << endl;

    int choice;
    string tmpChoice = "";
    cin >> tmpChoice;
    choice = atoi(tmpChoice.c_str());

    switch(choice)
    {
    case 1:
        searchCompLink();
        break;

    case 2:
        searchListLink();
        break;

    case 3:
        exit(0);
        break;

    default:
        cout << "Invalid input! " << endl;
        searchCPLink();
        break;
    }
}

void RepLayer::searchCompLink()
{
    cout << "Choose one option" << endl;
    cout << "1) Search computer" << endl;
    cout << "2) Search build year" << endl;
    cout << "3) Search a type of computer" << endl;
    cout << "4) Search for if it was made" << endl;
    cout << "5) Exit" << endl;
    string tmpChoice = "";
    cin >> tmpChoice;
    int searchChoice = atoi(tmpChoice.c_str());
    int searchInteger;
    vector<string> CPlist;
    switch(searchChoice)
    {
        case 1:
            cout << "Type a computer: ";
            cin.ignore();
            getline(cin,tmpChoice);
            CPlist = d1.searchLinkByComputerName(tmpChoice);
            break;
        case 2:
            cout << "Type a build year: ";
            cin.ignore();
            getline(cin,tmpChoice);
            searchInteger = atoi(tmpChoice.c_str());
            CPlist = d1.searchLinkByComputerYear(searchInteger);
            break;
        case 3:
            cout << "Type a computer type: ";
            cin.ignore();
            getline(cin,tmpChoice);
            CPlist = d1.searchLinkByComputerType(tmpChoice);
            break;

        case 4:
            cout << "Was it made(Yes or No): ";
            cin.ignore();
            getline(cin,tmpChoice);
            tmpChoice = fixName(tmpChoice);
            cout << tmpChoice<<endl;
            CPlist = d1.searchLinkByComputerMade(tmpChoice);

            break;

        case 5:
            exit(0);
            break;

        default:
            searchComp();
            break;

    }

    if(searchChoice==4 && (tmpChoice!="Yes"&&tmpChoice !="No"))
    {
    }
    else
    {
        cout << "Links between Computers and Scientists" << endl;
        cout << "--------------------------------------------------" << endl;
        for (unsigned int i = 0; i < CPlist.size(); i++) {
            cout << CPlist.at(i) << endl;
        }
        cout << "--------------------------------------------------" << endl;
    }
}

void RepLayer::searchListLink()
{
    int searchChoice;
    cout << "Choose one option: " << endl;
    cout << "1) Search by name" << endl;
    cout << "2) Search by gender" << endl;
    cout << "3) Search by year of birth" << endl;
    cout << "4) Search by year of death" << endl;

    int searchBirthYear, searchDeathYear;
    string searchName, searchGender;
    string tmpChoice = "";
    cin >> tmpChoice;
    searchChoice = atoi(tmpChoice.c_str());
    vector<string> CPlist;
    switch(searchChoice)
    {
        case 1:
            cout << "Type a name: ";
            cin.ignore();
            getline(cin,searchName);
            CPlist = d1.searchLinkByPersonName(searchName);
            break;
        case 2:
            cout << "Type a gender: ";
            cin.ignore();
            getline(cin,searchGender);
            CPlist = d1.searchLinkByPersonGender(searchGender);
            break;

        case 3:
            cout << "Type a year of birth: ";
            cin.ignore();
            getline(cin,tmpChoice);
            searchBirthYear = atoi(tmpChoice.c_str());
            CPlist = d1.searchLinkByPersonBirthyear(searchBirthYear);
            break;

        case 4:
            cout << "Type a year of death: ";
            cin.ignore();
            getline(cin,tmpChoice);
            searchDeathYear = atoi(tmpChoice.c_str());
            CPlist = d1.searchLinkByPersonDeathYear(searchDeathYear);
            break;

        default:
            cout << "Number not available"<< endl;
            searchList();
    }

    cout << "Links between Computers and Scientists" << endl;
    cout << "--------------------------------------------------" << endl;



    for (unsigned int i = 0; i < CPlist.size(); i++) {
        cout << CPlist.at(i) << endl;
    }
    cout << "--------------------------------------------------" << endl;
}

