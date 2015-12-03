#ifndef COMPUTER_H
#define COMPUTER_H

#include <iostream>
using namespace std;

class Computer
{
public:
    Computer();
    // Default constructor

    Computer(string _name, int _builtYear, string _type, string _builtComputer);
    // Constructor that sets name, builtYear, type and builtComputer to input value.

    Computer(string _name, int _builtYear, string _type, string _builtComputer,int _id);
    // Constructor that sets name, builtYear, type,builtComputer and id to input value.

    string getName();
    // Returns the name of a Computer instance

    int getBuiltYear();
    // Returns the built year of a Computer instance

    string getType();
    // Returns the type of a Computer instance

    string getBuiltComputer();
    // Returns whether a Computer was built or not

    int getId();
    // Returns the computer id

    void setName(string _name);
    // Sets the name of a Computer instance to input value

    void setBuiltYear(int _builtYear);
    // Sets the built year of a Computer instance to input value

    void setType(string _type);
    // Sets the type of a Computer instance to input value

    void setBuiltComputer(string _builtComputer);
    // Sets whether a Computer was built or not

    void setId(int _id);
    // Sets the computers id

private:
    string name;
    int builtYear;
    string type;
    string builtComputer;
    int id;
};

#endif // COMPUTER_H
