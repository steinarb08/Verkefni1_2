#include "datalayer.h"
#include <cstddef>

DataLayer::DataLayer()
{

}

void DataLayer::test()
{
    Person p1("Jón","male",1985,2016);
    Person p2("Erla","female",1980,2046);
    Person p3("Aron","male",1975,2036);
    vector<Person> perList;
    perList.push_back(p1);
    perList.push_back(p2);
    perList.push_back(p3);
    string data_test = "Testing this file";

    /*ofstream myfile;
    myfile.open("datafile.txt");
    myfile << data_test << endl;
    myfile.close();

    cout << "HI WORLD" << endl;*/
    //save(perList);
    vector<Person> loadList = load();
    cout << loadList.at(0).getName();


}

void DataLayer::save(vector<Person> getList)
{
    ofstream myfile;
    myfile.open("datafile.txt");

    int size = getList.size();

    for (int i = 0; i < size; i++)
    {
        myfile << getList.at(i).getName() << ":";
        myfile << getList.at(i).getGender() << ":";
        myfile << getList.at(i).getBirthYear() << ":";
        myfile << getList.at(i).getDeathYear() << endl;
    }
    myfile.close();

}
vector<Person> DataLayer::load()
{
    vector<Person> list;
    string line;

    ifstream myfile ("datafile.txt");
    if (myfile.is_open())
    {
        while ( getline(myfile,line) )
        {
            list.push_back(getString(line));
        }
        myfile.close();
    }
    return list;
}

Person DataLayer::getString(string line)
{
    int pos = line.find_first_of(':');
    string name = line.substr(0,pos);

    line.erase(0, pos +1);


    pos = line.find_first_of(':');
    string gender = line.substr(0, pos);
    line.erase(0, pos + 1);


    pos = line.find_first_of(':');
    int birth = atoi(line.substr(0, pos).c_str());
    line.erase(0, pos +1);

    int death = atoi(line.c_str());

    Person retP(name,gender,birth,death);
    return retP;
}

