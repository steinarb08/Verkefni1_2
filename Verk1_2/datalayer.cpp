#include "datalayer.h"

DataLayer::DataLayer()
{

}

void DataLayer::test()
{
    Person p1("Jón","male",1985,2016);
    Person p2("Erla","female",1980,2046);
    Person p3("Aron","male",1975,2036);
    list<Person> perList;
    perList.push_back(p1);
    perList.push_back(p2);
    perList.push_back(p3);
    string data_test = "Testing this file";

    /*ofstream myfile;
    myfile.open("datafile.txt");
    myfile << data_test << endl;
    myfile.close();

    cout << "HI WORLD" << endl;*/
    save(perList);

}

void DataLayer::save(list<Person> getList)
{
    ofstream myfile;
    myfile.open("datafile.txt");

    int size = getList.size();

    for (int i = 0; i < size; i++)
    {
        myfile << getList.front().getName() << ":";
        myfile << getList.front().getGender() << ":";
        myfile << getList.front().getBirthYear() << ":";
        myfile << getList.front().getDeathYear() << endl;
        getList.pop_front();
    }
    myfile.close();

}
list<Person> DataLayer::load(string fileName)
{


}
