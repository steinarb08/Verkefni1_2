#include "domainlayer.h"

DomainLayer::DomainLayer()
{
    // intentionally blank
}

vector<Person> DomainLayer::sortFromAtoZ(vector<Person> personList){            //Sorts the names in alphabetical order (A-Z) using bubble sort.
    DataLayer d1;
    return d1.loadDbPersonSort("name",1);
}

void DomainLayer::swap(Person& per1, Person& per2){
    Person temp = per1;
    per1 = per2;
    per2 = temp;
}

string DomainLayer::intToString(int n)
{
    ostringstream convert;
    convert<< n;
    return convert.str();
}

vector<Person> DomainLayer::reverse(vector<Person> personList){             //Sorts the names in reverse alphabetical order (Z-A) using bubble sort.
    DataLayer d1;
    return d1.loadDbPersonSort("name",0);
}

vector<Person> DomainLayer::sortGender(vector<Person> personList){          //Sorts the list by gender in alphabetical order using bubble sort.
    DataLayer d1;
    return d1.loadDbPersonSort("gender",1);
}

vector<Person> DomainLayer::reverseGender(vector<Person> personList){       //Sorts the list by gender in reverse alphabetical order using bubble sort.
    DataLayer d1;
    return d1.loadDbPersonSort("gender",0);
}

vector<Person> DomainLayer::sortBirthYear(vector<Person> personList){           //Sorts the list by year of birth in ascending order using bubble sort.
    DataLayer d1;
    return d1.loadDbPersonSort("birthyear",1);
}

vector<Person> DomainLayer::sortBirthYearDescending(vector<Person> personList){     //Sorts the list by year of birth in descending order using bubble sort.
    DataLayer d1;
    return d1.loadDbPersonSort("birthyear",0);
}


vector<Person> DomainLayer::sortDeathYear(vector<Person> personList){               //Sorts the list by year of death in ascending order using bubble sort.
    DataLayer d1;
    return d1.loadDbPersonSort("deathyear",1);
}


vector<Person> DomainLayer::sortDeathYearDescending(vector<Person> personList){     //Sorts the list by year of death in descending order using bubble sort.
    DataLayer d1;
    return d1.loadDbPersonSort("deathyear",0);
}


// Searches for a substring (searchString) in the name of each Person in a list, returns a sublist that has those substrings
vector<Person> DomainLayer::searchNameFunc(string searchString,vector<Person> mainList)
{
    DataLayer d1;
    return d1.searchDbPerson("name", searchString);

}

// Searches for a specific gender in a list og Persons and returns a list with all of the searched for gender.
vector<Person> DomainLayer::searchGenderFunc(string searchString,vector<Person> mainList)
{
    DataLayer d1;
    return d1.searchDbPerson("gender", searchString);
}

// Searches for a specific year of birth in a list of Persons and return a list with all those who have that year of birth.
vector<Person> DomainLayer::searchBirthYearFunc(int searchString,vector<Person> mainList)
{
    DataLayer d1;
    return d1.searchDbPerson("year of birth", intToString(searchString));
}

// Searches for a specific year of death in a list of Persons and return a list with all those who have that year of death.
vector<Person> DomainLayer::searchDeathYearFunc(int searchString,vector<Person> mainList)
{
    DataLayer d1;
    return d1.searchDbPerson("year of death", intToString(searchString));
}

// Add a person to database
void DomainLayer::addPersonToDB(Person newPerson){
    DataLayer data1;
    data1.insertToDbPerson(newPerson);
}

// Add a person to database
void DomainLayer::addComputerToDB(Computer newComputer)
{
    DataLayer data1;
    data1.insertToDbComputer(newComputer);
}


vector<Person> DomainLayer::loadPerson(){
    DataLayer data1;

    return data1.loadDbPerson();
}

vector<Computer> DomainLayer::loadComputer(){
    DataLayer data1;

    return data1.loadDbComputer();
}
