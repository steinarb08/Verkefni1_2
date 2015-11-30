#include <QCoreApplication>
#include <iostream>
#include <person.h>

#include <replayer.h>

#include <datalayer.h>

using namespace std;


vector<Person> personList;


// Should probably be in the domain layer.
void addPerson(Person newPerson)
{
    personList.push_back(newPerson);
}

int main(int argc, char *argv[])
{

   Person p1("Jon", "male", 2005, 2010);
   Person p2("Siggi", "male", 1909, 2000);
   Person p3 ("Gummi", "male", 1980, 2050);

   personList.push_back(p1);
   personList.push_back(p2);
   personList.push_back(p3);

   RepLayer rep1(personList);
   while(true)
   {
       rep1.startScreen();
   }

    QCoreApplication a(argc, argv);
    return 0;
}

