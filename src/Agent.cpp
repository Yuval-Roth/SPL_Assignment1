#include "../include/Agent.h"
#include "../include/Simulation.h"
#include <stdexcept>

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy), coalitionId(-1)
{
    // You can change the implementation of the constructor, but not the signature!
}

int Agent::getId() const
{
    return mAgentId;
}

int Agent::getPartyId() const
{
    return mPartyId;
}

void Agent::step(Simulation &sim)
{
    // TODO: implement this method
}

void Agent::setCoalition(int coalitionId)
{
    if(not alreadySet)
    {
        this->coalitionId = coalitionId;
        alreadySet = true;
    }
    // else throw std::runtime_error("Cannot change coalitions once they are set");
}
int Agent::getCoalition()
{
    return coalitionId;
}
