#pragma once

#include <list>
#include "Party.h"

using std::list;

class Coalition
{
    private:
    
    list<const Party &> Members;
    list<int> Already_Proposed;


    public:

    Coalition(int CoalitionId) : CoalitionId(CoalitionId){};
    const int CoalitionId;
    const bool checkIfAlreadyProposed(int PartyId);
    void addParty(const Party & party);
    const list<const Party&>& getMembers();

};

