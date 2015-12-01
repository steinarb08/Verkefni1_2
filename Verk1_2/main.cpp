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
    //Create a user interface (RepLayer)
   RepLayer rep1(personList);

   // Load data from file
   rep1.loadFromFile();

   // Run the welcome screen until user decides to quit.
   while(true)
   {
       rep1.startScreen();
   }
    QCoreApplication a(argc, argv);
    return 0;
}

