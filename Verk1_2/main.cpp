#include <QCoreApplication>
#include <iostream>
#include <person.h>
#include <replayer.h>
#include <datalayer.h>
#include <replayer.h>
#include <datalayer.h>
#include <domainlayer.h>
using namespace std;
vector<Person> personList;
int main(int argc, char *argv[])
{
   RepLayer userInt(personList);


   RepLayer rep1(personList);
   while(true)
   {
       rep1.startScreen();
   }
    QCoreApplication a(argc, argv);
    return 0;
}

