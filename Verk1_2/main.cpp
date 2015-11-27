#include <QCoreApplication>
#include <iostream>
#include <person.h>
using namespace std;


list<Person> personList;


// Should probably be in the domain layer.
void addPerson(Person newPerson)
{
    personList.push_back(newPerson);
}

int main(int argc, char *argv[])
{
    cout << "flot" << endl;
    Person person1("Jón","male",1985,2016);
    addPerson(person1);
    QCoreApplication a(argc, argv);
    return 0;
}

