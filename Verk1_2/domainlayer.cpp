#include "domainlayer.h"

DomainLayer::DomainLayer()
{
    // Intentionally blank
}

// Sorts the names in alphabetical order (A-Z).
vector<Person> DomainLayer::sortFromAtoZ()
{
    return d1.loadDbPersonSort("pname",1);
}

// Convert int to string
string DomainLayer::intToString(int n)
{
    ostringstream convert;
    convert<< n;
    return convert.str();
}

//Sorts the names in reverse alphabetical order (Z-A).
vector<Person> DomainLayer::reverse()
{
    return d1.loadDbPersonSort("pname",0);
}

//Sorts the list by gender in alphabetical order.
vector<Person> DomainLayer::sortGender()
{
    return d1.loadDbPersonSort("gender",1);
}

//Sorts the list by gender in reverse alphabetical order.
vector<Person> DomainLayer::reverseGender()
{
    return d1.loadDbPersonSort("gender",0);
}

//Sorts the list by year of birth in ascending order.
vector<Person> DomainLayer::sortBirthYear()
{
    return d1.loadDbPersonSort("birthyear",1);
}

//Sorts the list by year of birth in descending order.
vector<Person> DomainLayer::sortBirthYearDescending()
{
    return d1.loadDbPersonSort("birthyear",0);
}

//Sorts the list by year of death in ascending order.
vector<Person> DomainLayer::sortDeathYear()
{
    return d1.loadDbPersonSort("deathyear",1);
}

//Sorts the list by year of death in descending order.
vector<Person> DomainLayer::sortDeathYearDescending()
{
    return d1.loadDbPersonSort("deathyear",0);
}

// Searches for a substring (searchString) in the name of each Person in a list, returns a sublist that has those substrings
vector<Person> DomainLayer::searchNameFunc(string searchString)
{
    return d1.searchDbPerson("pname", searchString);
}

// Searches for a specific gender in a list og Persons and returns a list with all of the searched for gender.
vector<Person> DomainLayer::searchGenderFunc(string searchString)
{
    return d1.searchDbPerson("gender", searchString);
}

// Searches for a specific year of birth in a list of Persons and return a list with all those who have that year of birth.
vector<Person> DomainLayer::searchBirthYearFunc(int searchString)
{
    return d1.searchDbPerson("birthyear", intToString(searchString));
}

// Searches for a specific year of death in a list of Persons and return a list with all those who have that year of death.
vector<Person> DomainLayer::searchDeathYearFunc(int searchString)
{
    return d1.searchDbPerson("deathyear", intToString(searchString));
}

// Add a person to database
void DomainLayer::addPersonToDB(Person newPerson){
    d1.insertToDbPerson(newPerson);
}

// Add a computer to database
void DomainLayer::addComputerToDB(Computer newComputer)
{
    d1.insertToDbComputer(newComputer);
}

// Load list of persons
vector<Person> DomainLayer::loadPerson(){
    return d1.loadDbPerson();
}

// Load list of Computers
vector<Computer> DomainLayer::loadComputer(){
    return d1.loadDbComputer();
}

// Sorts the computer names in alphabetical order (A-Z).
vector<Computer> DomainLayer::sortFromAtoZ_C(){
    return d1.loadDbComputerSort("cname", 1);
}

// Sorts the computer names in reverse alphabetical order (Z-A).
vector<Computer> DomainLayer::reverse_C(){
    return d1.loadDbComputerSort("cname", 0);
}

// Sorts the computer list by when they were built in ascending order.
vector<Computer> DomainLayer::sortYearBuild_C()
{
    return d1.loadDbComputerSort("byear",1);
}

// Sorts the computer list by when they were built in descending order.
vector<Computer> DomainLayer::sortYearBuildReverse_C()
{
    return d1.loadDbComputerSort("byear",0);
}

// Sorts the computer type names in alphabetical order (A-Z).
vector<Computer> DomainLayer::sortType_C()
{
    return d1.loadDbComputerSort("type",1);
}

// Sorts the computer type names in reverse alphabetical order (Z-A).
vector<Computer> DomainLayer::sortTypeReverse_C()
{
    return d1.loadDbComputerSort("type",0);
}

// Sorts the computer list by whether it was made or not in alphabetical order.
vector<Computer> DomainLayer::sortMade_C()
{
    return d1.loadDbComputerSort("made",1);
}

// Sorts the comptuer list by whether it was made or not in reverse alphabetical order.
vector<Computer> DomainLayer::sortMadeReverse_C()
{
    return d1.loadDbComputerSort("made",0);
}

// Searches for a substring (searchString) in the name of each Computer in a list, returns a sublist that has those substrings
vector<Computer> DomainLayer::searchName_C(string searchString)
{
    return d1.searchDbComputer("cname",searchString);
}

// Searches for a specific year in a list of Computer and returns a list with all computers who were made this year.
vector<Computer> DomainLayer::searchYear_C(int searchString)
{
    return d1.searchDbComputer("byear",intToString(searchString));
}

// Searches for a substring (searchString) in the type of each Computer in a list, returns a sublist that has those substrings.
vector<Computer> DomainLayer::searchType_C(string searchString)
{
    return d1.searchDbComputer("type",searchString);
}

// Searches for Computer which were made or not, returns a list of Computers which were made or not.
vector<Computer> DomainLayer::searchMade_C(string searchString)
{
    return d1.searchDbComputer("made",searchString);
}

// Delete a Person from database.
void DomainLayer::deleteFromPerson(Person delPerson)
{
    d1.deleteFromDbPerson(delPerson);
}

// Delete a Computer from database.
void DomainLayer::deleteFromComputer(Computer delComputer)
{
    d1.deleteFromDbComputer(delComputer);
}

// Delete a Link from database(Computer links to Person).
void DomainLayer::deleteFromCPlink(CPlink delLink)
{
    d1.deleteFromDbLink(delLink);
}

// Adds a Link between a Person and a Computer.
void DomainLayer::addCPlinkToDb(Person p1,Computer c1)
{
    d1.insertToDbCPLink(c1,p1);
}

// Load a list of Links.
vector<CPlink> DomainLayer::loadLink()
{
    return d1.loadDbCPlink();
}

// Print list of Links
vector<string> DomainLayer::printCPList()
{
    return d1.printCPlink();
}

// Create a new data base.
void DomainLayer::createDb()
{
    d1.dropTables();
    d1.createTables();
}
// Searches for a substring (searchString) in the type of each link by person name in a list, returns a sublist that has those substrings.
vector<string> DomainLayer::searchLinkByPersonName(string name)
{
    vector<CPlink> links = d1.searchLinkByPerson("pname",name);
    vector<string> returnVector;
    for(unsigned int i=0;i<links.size();i++)
    {
        string line = d1.getPersonFromId(links.at(i).getPersonId()).getName() + " is connected to " + d1.getComputerFromId(links.at(i).getComputerId()).getName();
        returnVector.push_back(line);
    }
    return returnVector;
}
// Searches for a substring (searchString) in the type of each link by person gender in a list, returns a sublist that has those substrings.
vector<string> DomainLayer::searchLinkByPersonGender(string gender)
{
    vector<CPlink> links = d1.searchLinkByPerson("gender",gender);
    vector<string> returnVector;
    for(unsigned int i=0;i<links.size();i++)
    {
        string line = d1.getPersonFromId(links.at(i).getPersonId()).getName() + " is connected to " + d1.getComputerFromId(links.at(i).getComputerId()).getName();
        returnVector.push_back(line);
    }
    return returnVector;
}
// Searches for a substring (searchString) in the type of each link by person birth year in a list, returns a sublist that has those substrings.
vector<string> DomainLayer::searchLinkByPersonBirthyear(int year)
{
    vector<CPlink> links = d1.searchLinkByPerson("birthyear",intToString(year));
    vector<string> returnVector;
    for(unsigned int i=0;i<links.size();i++)
    {
        string line = d1.getPersonFromId(links.at(i).getPersonId()).getName() + " is connected to " + d1.getComputerFromId(links.at(i).getComputerId()).getName();
        returnVector.push_back(line);
    }
    return returnVector;
}
// Searches for a substring (searchString) in the type of each link by person death year in a list, returns a sublist that has those substrings.
vector<string> DomainLayer::searchLinkByPersonDeathYear(int year)
{
    vector<CPlink> links = d1.searchLinkByPerson("deathyear",intToString(year));
    vector<string> returnVector;
    for(unsigned int i=0;i<links.size();i++)
    {
        string line = d1.getPersonFromId(links.at(i).getPersonId()).getName() + " is connected to " + d1.getComputerFromId(links.at(i).getComputerId()).getName();
        returnVector.push_back(line);
    }
    return returnVector;
}

// Searches for a substring (searchString) in the type of each link Computer name, returns a sublist that has those substrings.
vector<string> DomainLayer::searchLinkByComputerName(string name)
{
    vector<CPlink> links = d1.searchLinkByComputer("cname",name);
    vector<string> returnVector;
    for(unsigned int i=0;i<links.size();i++)
    {
        string line = d1.getPersonFromId(links.at(i).getPersonId()).getName() + " is connected to " + d1.getComputerFromId(links.at(i).getComputerId()).getName();
        returnVector.push_back(line);
    }
    return returnVector;
}
// Searches for a substring (searchString) in the type of each link Computer built year, returns a sublist that has those substrings.
vector<string> DomainLayer::searchLinkByComputerMade(string made)
{
    vector<CPlink> links = d1.searchLinkByComputer("made",made);
    vector<string> returnVector;
    for(unsigned int i=0;i<links.size();i++)
    {
        string line = d1.getPersonFromId(links.at(i).getPersonId()).getName() + " is connected to " + d1.getComputerFromId(links.at(i).getComputerId()).getName();
        returnVector.push_back(line);
    }
    return returnVector;
}
// Searches for a substring (searchString) in the type of each link Computer type, returns a sublist that has those substrings.
vector<string> DomainLayer::searchLinkByComputerType(string type)
{
    vector<CPlink> links = d1.searchLinkByComputer("type",type);
    vector<string> returnVector;
    for(unsigned int i=0;i<links.size();i++)
    {
        string line = d1.getPersonFromId(links.at(i).getPersonId()).getName() + " is connected to " + d1.getComputerFromId(links.at(i).getComputerId()).getName();
        returnVector.push_back(line);
    }
    return returnVector;
}
// Searches for a substring (searchString) in the type of each link Computer year, returns a sublist that has those substrings.
vector<string> DomainLayer::searchLinkByComputerYear(int year)
{
    vector<CPlink> links = d1.searchLinkByComputer("byear",intToString(year));
    vector<string> returnVector;
    for(unsigned int i=0;i<links.size();i++)
    {
        string line = d1.getPersonFromId(links.at(i).getPersonId()).getName() + " is connected to " + d1.getComputerFromId(links.at(i).getComputerId()).getName();
        returnVector.push_back(line);
    }
    return returnVector;
}
// Return a update person.
vector<Person> DomainLayer::updatePerson(Person p1)
{
    return d1.updateDbPerson(p1);
}
// Return a update computer.
vector<Computer> DomainLayer::updateComputer(Computer c1)
{
    return d1.updateDbComputer(c1);
}

vector<Person> DomainLayer::loadPersonLinkedWith(Computer c1)
{
    vector<CPlink> allLinks = d1.loadLinkByComputer(intToString(c1.getId()));
    vector<Person> linkedPerson;
    for(unsigned int i=0;i<allLinks.size();i++)
    {
        linkedPerson.push_back(d1.getPersonFromId(allLinks.at(i).getPersonId()));
    }
    return linkedPerson;
}

vector<Computer> DomainLayer::loadComputerLinkedWith(Person p1)
{
    vector<CPlink> allLinks = d1.loadLinkByPerson(intToString(p1.getId()));
    vector<Computer> linkedComputer;
    for(unsigned int i=0;i<allLinks.size();i++)
    {
        linkedComputer.push_back(d1.getComputerFromId(allLinks.at(i).getComputerId()));
    }
    return linkedComputer;
}

void DomainLayer::connectToDatabase()
{
    d1.connect();
}

// Used to put names in standard format (capital letter at the begining and only at the begining of each name).
string DomainLayer::fixName(string name)
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

void DomainLayer::deleteFromCPlink(Person p1, Computer c1)
{
    d1.deleteFromDbLink(p1,c1);
}
