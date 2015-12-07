#include "cplink.h"

CPlink::CPlink()
{
    //intentionally blank
}

// Constructor that sets computer Id and person Id to input value.
CPlink::CPlink(int _computerId, int _personId)
{
    computerId = _computerId;
    personId = _personId;
    linkId = 0;
}

// Constructor that sets computer Id, person Id and link Id.
// Link person to a computer.
CPlink::CPlink(int _computerId, int _personId, int _linkId)
{
    computerId = _computerId;
    personId = _personId;
    linkId = _linkId;
}

// Get the id of the computer associated with the link
int CPlink::getComputerId()
{
    return computerId;
}

// Get the id of the Person associated with the link
int CPlink::getPersonId()
{
    return personId;
}

// Get the id of this particular link
int CPlink::getLinkId()
{
    return linkId;
}

