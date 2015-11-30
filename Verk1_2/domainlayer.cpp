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
