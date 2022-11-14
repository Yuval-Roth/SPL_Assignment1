#include "../include/Agent.h"
#include "../include/Simulation.h"
#include "../include/SelectionPolicy.h"
#include <stdexcept>
#include <list>
using std::list;


Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId),
 mSelectionPolicy(selectionPolicy),  alreadySet(false),coalitionId(-1)
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
    const Graph& graph = sim.getGraph();
    Coalition& coalition = sim.getCoalition(coalitionId);
    int pCount = graph.getNumVertices();
    list<Party> partiesToPropose;
    for(int i = 0; i< pCount ; i++)
    {
        if(i != mPartyId && coalition.checkIfAlreadyProposed(i))
        {
            if(graph.getEdgeWeight(i,mPartyId) > 0)
            {
                partiesToPropose.push_front(graph.getParty(i));
            }            
        }
    }
    Party& toPropose = mSelectionPolicy -> selectParty(partiesToPropose);
    toPropose.acceptOffer(coalition.CoalitionId);
    coalition.flagAsProposed(toPropose.getId());
}

void Agent::setCoalition(int coalitionId)
{
    if(not alreadySet)
    {
        this->coalitionId = coalitionId;
        alreadySet = true;
    }
    else throw std::runtime_error("Cannot change coalitions once they are set");
}
int Agent::getCoalition()
{
    return coalitionId;
}
