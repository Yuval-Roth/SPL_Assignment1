#include "../include/Agent.h"
#include "../include/Simulation.h"
#include "../include/SelectionPolicy.h"
#include "../include/Party.h"
#include <stdexcept>
#include <list>
using std::list;

//constructors

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy,bool alreadySet,Coalition* coalition) : mAgentId(agentId),
 mPartyId(partyId),mSelectionPolicy(selectionPolicy),alreadySet(alreadySet),coalition(coalition){}

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy, Coalition* coalition) : Agent(agentId,partyId,selectionPolicy,true,coalition){}

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : Agent(agentId,partyId,selectionPolicy,false,NULL){}

Agent::Agent(const Agent& other):mAgentId(other.mAgentId),mPartyId(other.mPartyId),mSelectionPolicy(other.mSelectionPolicy->clone()),alreadySet(other.alreadySet),coalition(other.coalition){}

Agent& Agent::operator=(const Agent& other)
{
    mAgentId = other.mAgentId;
    mPartyId = other.mPartyId;
    if(other.mSelectionPolicy != NULL)
        mSelectionPolicy = other.mSelectionPolicy->clone();
    alreadySet = other.alreadySet;
    coalition = other.coalition;
    return *this;
}

Agent::Agent(Agent&& rvalue) : Agent(rvalue.mAgentId,rvalue.mPartyId,rvalue.mSelectionPolicy,rvalue.alreadySet,rvalue.coalition)
{
    rvalue.mSelectionPolicy = NULL;
    rvalue.coalition = NULL;
}
Agent& Agent::operator=(Agent&& rvalue)
{
    mAgentId = rvalue.mAgentId;
    mPartyId = rvalue.mPartyId;
    delete mSelectionPolicy;
    mSelectionPolicy = rvalue.mSelectionPolicy;
    alreadySet = rvalue.alreadySet;
    coalition = rvalue.coalition;
    
    rvalue.mSelectionPolicy = NULL;
    rvalue.coalition = NULL;

    return *this;
}


//=========================================================================================================

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
    Graph& graph = sim.getGraph();
    int pCount = graph.getNumVertices();
    list<Party*> partiesToPropose;
    for(int i = 0; i< pCount ; i++)
    {
        if(i != mPartyId && sim.getParty(i).getState() != State::Joined && graph.getEdgeWeight(i,mPartyId) > 0 && coalition->checkIfAlreadyProposed(i) == false)
        {
            partiesToPropose.push_front(&(graph.getParty(i)));         
        }
    }
    if(partiesToPropose.empty() == false)
    {
        //Do not delete toPropose
        Party* toPropose = mSelectionPolicy -> selectParty(partiesToPropose,sim.getGraph(),mPartyId);
        toPropose->acceptOffer(*coalition,sim);
        coalition->flagAsProposed(toPropose->getId());
    }
}

void Agent::setCoalition(Coalition& coalition)
{
    if(alreadySet == false)
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

SelectionPolicy* Agent::getSelectionPolicy()
{
    return mSelectionPolicy;
}
Agent::~Agent()
{
    delete mSelectionPolicy;
}
