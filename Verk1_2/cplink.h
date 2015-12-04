#ifndef CPLINK_H
#define CPLINK_H


class CPlink
{
public:
    CPlink();
    // Default constructor (not used)

    CPlink(int _computerId,int _personId);

    CPlink(int _computerId, int _personId,int _linkId);

    int getComputerId();
    // Get the id of the computer associated with the link

    int getPersonId();
    // Get the id of the Person associated with the link

    int getLinkId();
    // Get the id of this particular link
private:
    int computerId;
    int personId;
    int linkId;
};

#endif // CPLINK_H
