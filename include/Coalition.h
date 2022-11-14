#ifndef Coalitions_h
#define Coalitions_h

#include <list>
#include "Party.h"

using std::list;

class Coalition
{
    private:
    
    list<int> Members;
    list<int> Already_Proposed;


    public:
    
    Coalition(int CoalitionId);
    bool checkIfAlreadyProposed(int partyId) const;
    void flagAsProposed(int partyId);
    void addParty(int partyId);
    const list<int>& getMembers() const;

    const int CoalitionId;

};
#endif
