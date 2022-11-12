#pragma once

#include <list>
#include "Party.h"

using std::list;

class Coalition
{
    private:
    
    list<Party &>* Members;
    list<int>* Already_Proposed;

    public:

    Coalition(int CoalitionId) : CoalitionId(CoalitionId){};
    const int CoalitionId;
    const bool CheckIfAlreadyProposed(int PartyId);
    void AddParty(Party & party);

};

