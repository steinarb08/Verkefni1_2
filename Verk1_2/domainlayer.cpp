#include "domainlayer.h"

DomainLayer::DomainLayer()
{
    // intentionally blank
}

vector<Person> DomainLayer::sortFromAtoZ(vector<Person> personList){
    bool swapped;
    do
    {
        swapped = false;
        for(unsigned int i = 1; i < personList.size(); i++)
        {
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

vector<Person> DomainLayer::reverse(vector<Person> personList){
    std::reverse(personList.begin(), personList.end());

    return personList;
}




