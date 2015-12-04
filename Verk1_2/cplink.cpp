#include "cplink.h"

CPlink::CPlink()
{

}

CPlink::CPlink(int _computerId, int _personId)
{
    computerId = _computerId;
    personId = _personId;
    linkId = 0;
}

CPlink::CPlink(int _computerId, int _personId, int _linkId)
{
    computerId = _computerId;
    personId = _personId;
    linkId = _linkId;
}

int CPlink::getComputerId()
{
    return computerId;
}

int CPlink::getPersonId()
{
    return personId;
}

int CPlink::getLinkId()
{
    return linkId;
}

