#ifndef Coalitions_h
#define Coalitions_h

#include <list>
#include "Party.h"
#include "Agent.h"

class Coalition
{
    private:
    
    //fields

    list<int> Members;
    list<int> Already_Proposed;
    Agent agent_for_copying;

    public:
    
    //Fields

    const int CoalitionId;
    int mandatesCount;

    //constructors

    Coalition(int coalitionId);
    Coalition(int coalitionId,int firstParty);

    //methods

    bool checkIfAlreadyProposed(int) const;
    void flagAsProposed(int);
    void addParty(int,Simulation&);
    const list<int>& getMembers() const;
    list<int>& getMembers();
    const int& getMandatesCount() const;
    void setAgent(const Agent& other);

};
#endif
