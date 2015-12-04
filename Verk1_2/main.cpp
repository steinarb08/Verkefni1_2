#include <QCoreApplication>
#include <iostream>
#include <person.h>
#include <replayer.h>
#include <datalayer.h>
#include <replayer.h>
#include <datalayer.h>
#include <domainlayer.h>
#include <computer.h>
using namespace std;
vector<Person> personList;
vector<Computer> computerList;
int main(int argc, char *argv[])
{
    //Create a user interface (RepLayer)
   RepLayer rep1(personList, computerList);

   // Load data from file
   rep1.loadFromFile();

   // Run the welcome screen until user decides to quit.
   while(true)
   {
       rep1.firstStartScreen();
   }
    QCoreApplication a(argc, argv);
    return 0;
}

