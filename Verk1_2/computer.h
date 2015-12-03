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

    string getName();
    // Returns the name of a Computer instance

    int getBuiltYear();
    // Returns the built year of a Computer instance

    string getType();
    // Returns the type of a Computer instance

    string getBuiltComputer();
    // Returns whether a Computer was built or not

    void setName(string _name);
    // Sets the name of a Computer instance to input value

    void setBuiltYear(int _builtYear);
    // Sets the built year of a Computer instance to input value

    void setType(string _type);
    // Sets the type of a Computer instance to input value

    void setBuiltComputer(string _builtComputer);
    // Sets whether a Computer was built or not

private:
    string name;
    int builtYear;
    string type;
    string builtComputer;
};

#endif // COMPUTER_H
