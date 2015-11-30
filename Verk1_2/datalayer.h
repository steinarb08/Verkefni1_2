#ifndef DATALAYER_H
#define DATALAYER_H
#include <replayer.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>

class DataLayer
{
public:
    DataLayer();
    void test();
    void save(vector<Person> getList);
    vector<Person> load();
    Person getString(string line);
};

#endif // DATALAYER_H
