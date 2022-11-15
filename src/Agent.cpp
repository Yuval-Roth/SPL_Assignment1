#include "../include/Agent.h"
#include "../include/Simulation.h"
#include "../include/SelectionPolicy.h"
#include "../include/Party.h"
#include <stdexcept>
#include <list>
using std::list;

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy, Coalition* coalition) : mAgentId(agentId),
 mPartyId(partyId),mSelectionPolicy(selectionPolicy),alreadySet(false),coalition(coalition)

{
    // You can change the implementation of the constructor, but not the signature!
}

//This constructor sets the coalition to be NULL
Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId)
,mSelectionPolicy(selectionPolicy),alreadySet(false),coalition(NULL)
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
    Graph& graph = sim.getGraph_non_const();
    int pCount = graph.getNumVertices();
    list<Party*> partiesToPropose;
    for(int i = 0; i< pCount ; i++)
    {
        if(i != mPartyId && coalition->checkIfAlreadyProposed(i))
        {
            if(graph.getEdgeWeight(i,mPartyId) > 0)
            {
                partiesToPropose.push_front(&(graph.getParty_non_const(i)));
            }            
        }
    }

    //Do not delete toPropose
    Party* toPropose = mSelectionPolicy -> selectParty(partiesToPropose);
    toPropose->acceptOffer(*coalition);
    coalition->flagAsProposed(toPropose->getId());
}

void Agent::setCoalition(Coalition& coalition)
{
    if(not alreadySet)
    {
        this->coalition = &coalition;
        alreadySet = true;
    }
    else throw std::runtime_error("Cannot change coalitions once they are set");
}
Coalition& Agent::getCoalition()
{
    return *coalition;
}
