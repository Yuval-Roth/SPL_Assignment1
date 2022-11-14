#include "../include/Coalition.h"

Coalition::Coalition(int coalitionId) : Members(),Already_Proposed(),CoalitionId(coalitionId)
{
    
}

bool Coalition::checkIfAlreadyProposed(int partyId) const
{
    std::_List_const_iterator<int> iter ;
    for (iter = Already_Proposed.begin() ; iter != Already_Proposed.end() ; iter++)
    {
        if(*iter == partyId) return true;
    }
    for (iter = Members.begin() ; iter != Members.end() ; iter++)
    {
        if(*iter == partyId) return true;
    } 
    return false;
}

void Coalition::flagAsProposed(int partyId)
{
    Already_Proposed.push_front(partyId);
}

void Coalition::addParty(int partyId)
{
    Members.push_front(partyId);
    std::_List_iterator<int> iter ;
    for (iter = Already_Proposed.begin() ; iter != Already_Proposed.end() ; iter++)
    {
        if(*iter == partyId)
         {
          Already_Proposed.erase(iter);  
          break;
         }  
    } 
}

const list<int>& Coalition::getMembers() const
{
    return Members;
}
