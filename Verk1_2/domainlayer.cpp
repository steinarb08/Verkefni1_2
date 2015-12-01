#include "domainlayer.h"

DomainLayer::DomainLayer()
{
    // intentionally blank
}

vector<Person> DomainLayer::sortFromAtoZ(vector<Person> personList){            //Sorts the names in alphabetical order (A-Z) using bubble sort.
    bool swapped;
    do
    {
        swapped = false;
        for(unsigned int i = 1; i < personList.size(); i++)
        {
            //Swapping elements in if statement.
            if(personList.at(i-1).getName() > personList.at(i).getName())
            {
                swap(personList.at(i-1), personList.at(i));
                swapped = true;
            }
        }
    } while(swapped);

    return personList;
}

void DomainLayer::swap(Person& per1, Person& per2){
    Person temp = per1;
    per1 = per2;
    per2 = temp;
}

vector<Person> DomainLayer::reverse(vector<Person> personList){             //Sorts the names in reverse alphabetical order (Z-A) using bubble sort.
    personList = sortFromAtoZ(personList);
    std::reverse(personList.begin(), personList.end());

    return personList;
}

vector<Person> DomainLayer::sortGender(vector<Person> personList){          //Sorts the list by gender in alphabetical order using bubble sort.
    personList = sortFromAtoZ(personList);
    bool genderSwapped;
    do
    {
        genderSwapped = false;
        for(unsigned int i = 1; i < personList.size(); i++)
        {
            //Swapping elements in if statement.
            if(personList.at(i-1).getGender() > personList.at(i).getGender())
            {
                swap(personList.at(i-1), personList.at(i));
                genderSwapped = true;
            }
        }
    } while(genderSwapped);

    return personList;
}

vector<Person> DomainLayer::reverseGender(vector<Person> personList){       //Sorts the list by gender in reverse alphabetical order using bubble sort.
    personList = sortFromAtoZ(personList);
    bool genderSwapped;
    do
    {
        genderSwapped = false;
        for(unsigned int i = 1; i < personList.size(); i++)
        {
            //Swapping elements in if statement.
            if(personList.at(i-1).getGender() < personList.at(i).getGender())
            {
                swap(personList.at(i-1), personList.at(i));
                genderSwapped = true;
            }
        }
    } while(genderSwapped);

    return personList;
}

vector<Person> DomainLayer::sortBirthYear(vector<Person> personList){           //Sorts the list by year of birth in ascending order using bubble sort.
    personList = sortFromAtoZ(personList);
    bool birthSwapped;
    do
    {
        birthSwapped = false;
        for(unsigned int i = 1; i < personList.size(); i++)
        {
            //Swapping elements in if statement.
            if(personList.at(i-1).getBirthYear() > personList.at(i).getBirthYear())
            {
                swap(personList.at(i-1), personList.at(i));
                birthSwapped = true;
            }
        }
    } while(birthSwapped);

    return personList;
}

vector<Person> DomainLayer::sortBirthYearDescending(vector<Person> personList){     //Sorts the list by year of birth in descending order using bubble sort.
    personList = sortFromAtoZ(personList);
    bool birthSwapped;
    do
    {
        birthSwapped = false;
        for(unsigned int i = 1; i < personList.size(); i++)
        {
            //Swapping elements in if statement.
            if(personList.at(i-1).getBirthYear() < personList.at(i).getBirthYear())
            {
                swap(personList.at(i-1), personList.at(i));
                birthSwapped = true;
            }
        }
    } while(birthSwapped);

    return personList;
}


vector<Person> DomainLayer::sortDeathYear(vector<Person> personList){               //Sorts the list by year of death in ascending order using bubble sort.
    personList = sortFromAtoZ(personList);
    bool deathSwapped;
    do
    {
        deathSwapped = false;
        for(unsigned int i = 1; i < personList.size(); i++)
        {
            //Swapping elements in if statement.
            if(personList.at(i-1).getDeathYear() > personList.at(i).getDeathYear())
            {
                swap(personList.at(i-1), personList.at(i));
                deathSwapped = true;
            }
        }
    } while(deathSwapped);

    return personList;
}


vector<Person> DomainLayer::sortDeathYearDescending(vector<Person> personList){     //Sorts the list by year of death in descending order using bubble sort.
    personList = sortFromAtoZ(personList);
    bool deathSwapped;
    do
    {
        deathSwapped = false;
        for(unsigned int i = 1; i < personList.size(); i++)
        {
            //Swapping elements in if statement.
            if(personList.at(i-1).getDeathYear() < personList.at(i).getDeathYear())
            {
                swap(personList.at(i-1), personList.at(i));
                deathSwapped = true;
            }
        }
    } while(deathSwapped);

    return personList;
}


// Searches for a substring (searchString) in the name of each Person in a list, returns a sublist that has those substrings
vector<Person> DomainLayer::searchNameFunc(string searchString,vector<Person> mainList)
{
    vector<Person> newVector;
    int sizeOfList = mainList.size();

    for(int i = 0; i < sizeOfList; i++)
    {
        int it=0;
         it = mainList.at(i).getName().find(searchString);
         if(it != -1)
         {
             newVector.push_back(mainList.at(i));
         }


    }
    return newVector;
}

// Searches for a specific gender in a list og Persons and returns a list with all of the searched for gender.
vector<Person> DomainLayer::searchGenderFunc(string searchString,vector<Person> mainList)
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

// Searches for a specific year of birth in a list of Persons and return a list with all those who have that year of birth.
vector<Person> DomainLayer::searchBirthYearFunc(int searchString,vector<Person> mainList)
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

// Searches for a specific year of death in a list of Persons and return a list with all those who have that year of death.
vector<Person> DomainLayer::searchDeathYearFunc(int searchString,vector<Person> mainList)
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
