#include <QCoreApplication>
#include <iostream>
#include <person.h>
<<<<<<< HEAD
#include <replayer.h>
=======
#include <datalayer.h>
>>>>>>> fa8204fbbc0061e7caea5002ee057d0695c865fe
using namespace std;


list<Person> personList;


// Should probably be in the domain layer.
void addPerson(Person newPerson)
{
    personList.push_back(newPerson);
}

int main(int argc, char *argv[])
{

<<<<<<< HEAD
=======

>>>>>>> fa8204fbbc0061e7caea5002ee057d0695c865fe
    QCoreApplication a(argc, argv);
    return 0;
}

