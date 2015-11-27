#include "replayer.h"

RepLayer::RepLayer()
{

}

void RepLayer::printList(list <Person> personList)
{
    cout << "Name - Gender - Year of birth - Year of death" << endl;
    int size = personList.size();
    for(int i = 0; i < size; i++)
    {
        cout << personList.front().getName() << " - " << personList.front().getGender() << " - ";
        cout << personList.front().getBirthYear() << " - " << personList.front().getDeathYear() << endl;
        personList.pop_front();
    }
}

void RepLayer::test()
{
    list <Person> personList;

    Person person1("Jon","male",1985,2016);
    Person person2("Gummi", "male", 1950, 2010);
    Person person3("Siggi", "male", 1900, 1980);

    personList.push_back(person1);
    personList.push_back(person2);
    personList.push_back(person3);

    printList(personList);
}



