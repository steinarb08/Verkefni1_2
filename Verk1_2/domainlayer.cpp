#include "domainlayer.h"

DomainLayer::DomainLayer()
{
}

vector<Person> DomainLayer::sortFromAtoZ(){            //Sorts the names in alphabetical order (A-Z) using bubble sort.
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

vector<Person> DomainLayer::reverse(){             //Sorts the names in reverse alphabetical order (Z-A) using bubble sort.
    return d1.loadDbPersonSort("name",0);
}

vector<Person> DomainLayer::sortGender(){          //Sorts the list by gender in alphabetical order using bubble sort.
    return d1.loadDbPersonSort("gender",1);
}

vector<Person> DomainLayer::reverseGender(){       //Sorts the list by gender in reverse alphabetical order using bubble sort.
    return d1.loadDbPersonSort("gender",0);
}

vector<Person> DomainLayer::sortBirthYear(){           //Sorts the list by year of birth in ascending order using bubble sort.
    return d1.loadDbPersonSort("birthyear",1);
}

vector<Person> DomainLayer::sortBirthYearDescending(){     //Sorts the list by year of birth in descending order using bubble sort.
    return d1.loadDbPersonSort("birthyear",0);
}


vector<Person> DomainLayer::sortDeathYear(){               //Sorts the list by year of death in ascending order using bubble sort.
    return d1.loadDbPersonSort("deathyear",1);
}


vector<Person> DomainLayer::sortDeathYearDescending(){     //Sorts the list by year of death in descending order using bubble sort.
    return d1.loadDbPersonSort("deathyear",0);
}


// Searches for a substring (searchString) in the name of each Person in a list, returns a sublist that has those substrings
vector<Person> DomainLayer::searchNameFunc(string searchString)
{
    return d1.searchDbPerson("name", searchString);

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

// Add a person to database
void DomainLayer::addComputerToDB(Computer newComputer)
{
    d1.insertToDbComputer(newComputer);
}


vector<Person> DomainLayer::loadPerson(){
    return d1.loadDbPerson();
}

vector<Computer> DomainLayer::loadComputer(){
    return d1.loadDbComputer();
}

/*vector<Computer> DomainLayer::sortFromAtoZ(){
    return d1.loadDbComputerSort("name", 1);
}

vector<Computer> DomainLayer::reverse(){
    return d1.loadDbComputerSort("name", 0);
}*/
