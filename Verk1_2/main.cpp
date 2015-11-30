#include <QCoreApplication>
#include <iostream>
#include <person.h>
#include <replayer.h>
#include <datalayer.h>
#include <domainlayer.h>
using namespace std;


vector<Person> personList;


// Should probably be in the domain layer.
void addPerson(Person newPerson)
{
    personList.push_back(newPerson);
}

int main(int argc, char *argv[])
{
    RepLayer userInt(personList);
    while (true)
    {
        userInt.startScreen();
    }

    QCoreApplication a(argc, argv);
    return 0;
}

