#include <QCoreApplication>
#include <iostream>
#include <person.h>
#include <datalayer.h>
using namespace std;


list<Person> personList;


// Should probably be in the domain layer.
void addPerson(Person newPerson)
{
    personList.push_back(newPerson);
}

int main(int argc, char *argv[])
{
    DataLayer d1;

    d1.test();
    QCoreApplication a(argc, argv);
    return 0;
}

