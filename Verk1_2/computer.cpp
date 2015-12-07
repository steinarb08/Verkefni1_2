#include "computer.h"

Computer::Computer()
{
    //intentionally blank
}

// Constructor that sets name, builtYear, type and builtComputer to input value.
Computer::Computer(string _name, int _builtYear, string _type, string _builtComputer)
{
    name = _name;
    builtYear = _builtYear;
    type = _type;
    builtComputer = _builtComputer;
}

// Constructor that sets name, builtYear, type,builtComputer and id to input value.
Computer::Computer(string _name, int _builtYear, string _type, string _builtComputer,int _id)
{
    name = _name;
    builtYear = _builtYear;
    type = _type;
    builtComputer = _builtComputer;
    id = _id;
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

// Returns the computers id
int Computer::getId()
{
    return id;
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

// Sets computer Id to input value.
void Computer::setId(int _id)
{
    id = _id;
}

