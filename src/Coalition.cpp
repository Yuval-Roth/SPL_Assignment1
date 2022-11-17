#include "../include/Coalition.h"
#include "../include/Simulation.h"

Coalition::Coalition(int coalitionId,Party& firstParty) : Members(),Already_Proposed(1,-1),agent_for_copying(),CoalitionId(coalitionId)
,mandatesCount(0)
{
    Members.push_front(firstParty.getId());
    mandatesCount += firstParty.getMandates();
}

//This constructor creates an empty Agent_for_copying
Coalition::Coalition(int coalitionId) : Members(),Already_Proposed(),agent_for_copying(),CoalitionId(coalitionId)
,mandatesCount(0){}

// Coalition::Coalition(const Coalition& other):Members(other.Members),Already_Proposed(other.Already_Proposed),
// agent_for_copying(other.agent_for_copying),CoalitionId(other.CoalitionId),mandatesCount(other.mandatesCount){}

// Coalition& Coalition::operator=(const Coalition& other)
// {
//     Members = other.Members;
//     Already_Proposed = other.Already_Proposed;
//     agent_for_copying = other.agent_for_copying;
//     CoalitionId = other.CoalitionId;
//     mandatesCount = other.mandatesCount;
//     return *this;
// }

bool Coalition::checkIfAlreadyProposed(int partyId) const
{
    for(int id : Members)
    {
        if(id == partyId) return true;    
    }
    for(int id : Already_Proposed)
    {
        if(id == partyId) return true;    
    }
    return false;
}

void Coalition::flagAsProposed(int partyId)
{
    Already_Proposed.push_front(partyId);
}

void Coalition::addParty(int partyId, Simulation& sim)
{
    //removing the party from already_proposed list
    std::_List_iterator<int> iter ;
    for (iter = Already_Proposed.begin() ; iter != Already_Proposed.end() ; iter++)
    {
        if(*iter == partyId)
         {
          Already_Proposed.erase(iter);  
          break;
         }  
    }
    //===================================================================================

    Party& toAdd = sim.getParty(partyId);
    Members.push_front(partyId);
    mandatesCount += toAdd.getMandates();
    int newAgentId = sim.getAgents().size();
    sim.getAgents().push_back(Agent(newAgentId,partyId,agent_for_copying.getSelectionPolicy(),this));
}

const list<int>& Coalition::getMembers() const
{
    return Members;
}

const int& Coalition::getMandatesCount() const
{
    return mandatesCount;
}

void Coalition::setAgent_for_copying(const Agent& other)
{
    agent_for_copying = other;
}
