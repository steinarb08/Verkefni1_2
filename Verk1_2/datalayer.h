#ifndef DATALAYER_H
#define DATALAYER_H
#include <replayer.h>
#include <iostream>
#include <fstream>

class DataLayer
{
public:
    DataLayer();
    void test();
    void save(list<Person> getList);
    list<Person> load(string fileName);
};

#endif // DATALAYER_H
