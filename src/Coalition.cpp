#include "../include/Coalition.h"
#include "../include/Simulation.h"
#include "../include/Agent.h"

Coalition::Coalition(int coalitionId,const Agent& agent) : Members(),Already_Proposed(),agent_for_copying(agent),CoalitionId(coalitionId)
,mandatesCount(0){}

//This constructor creates an empty Agent_for_copying
Coalition::Coalition(int coalitionId) : Members(),Already_Proposed(),agent_for_copying(),CoalitionId(coalitionId)
,mandatesCount(0){}

bool Coalition::checkIfAlreadyProposed(int partyId) const
{
    std::_List_const_iterator<int> iter ;
    for (iter = Members.begin() ; iter != Members.end() ; iter++)
    {
        if(*iter == partyId) return true;
    } 
    for (iter = Already_Proposed.begin() ; iter != Already_Proposed.end() ; iter++)
    {
        if(*iter == partyId) return true;
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
