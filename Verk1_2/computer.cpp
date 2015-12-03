#include "computer.h"

Computer::Computer()
{

}

// Constructor that sets name, builtYear, type and builtComputer to input value.
Computer::Computer(string _name, int _builtYear, string _type, string _builtComputer)
{
    name = _name;
    builtYear = _builtYear;
    type = _type;
    builtComputer = _builtComputer;
}

// Returns the name of a Computer instance
string Computer::getName()
{
    return name;
}

// Returns the built year of a Computer instance
int Computer::getBuiltYear()
{
    return builtYear;
}

// Returns the type of a Computer instance
string Computer::getType()
{
    return type;
}

// Returns whether a Computer was built or not
string Computer::getBuiltComputer()
{
    return builtComputer;
}

// Sets the name of a Computer instance to input value
void Computer::setName(string _name)
{
    name = _name;
}

// Sets the built year of a Computer instance to input value
void Computer::setBuiltYear(int _builtYear)
{
    builtYear = _builtYear;
}

// Sets the type of a Computer instance to input value
void Computer::setType(string _type)
{
    type = _type;
}

// Sets whether a Computer was built or not
void Computer::setBuiltComputer(string _builtComputer)
{
    builtComputer = _builtComputer;
}

