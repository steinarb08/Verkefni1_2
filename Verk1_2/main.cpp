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
    Person p1("Steinar","male",1985,2020);
    Person p2("Gunni","male",1970,2000);
    Person p3("Olafur","male",1972,2033);
    Person p4("Petur","male",1920,2010);
    Person p5("Alex","male",1960,2030);
    Person p6("Trausti","male",1970,2000);
    Person p7("Tryggvi","male",1935,2130);

    personList.push_back(p1);
    personList.push_back(p2);
    personList.push_back(p3);
    personList.push_back(p4);
    personList.push_back(p5);
    personList.push_back(p6);
    personList.push_back(p7);

    DomainLayer d1;
    personList = d1.sortFromAtoZ(personList);

    personList = d1.reverse(personList);

    RepLayer rep1(personList);
    rep1.printList(personList);

    QCoreApplication a(argc, argv);
    return 0;
}

