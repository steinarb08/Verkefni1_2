#include <QCoreApplication>
#include <iostream>
#include <person.h>
#include <replayer.h>
#include <datalayer.h>
using namespace std;

vector<Person> personList;

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

