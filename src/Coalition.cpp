#include "../include/Coalition.h"

const bool Coalition::checkIfAlreadyProposed(int PartyId)
{

    
    // TODO : Complete this implementation
    return true;

}

void Coalition::addParty(int partyId)
{
    Members.push_front(partyId);
}

const list<int>& Coalition::getMembers() const
{
    return Members;
}
