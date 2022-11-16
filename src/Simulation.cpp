#include "../include/Simulation.h"
#include "../include/Graph.h"

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph),
mAgents(agents), coalitions(),CoalitionIdCounter(0),collectingOffersParties() 
{   
    for(Agent& agent : mAgents)
    {
        Coalition coalition = Coalition(CoalitionIdCounter++,agent.getPartyId());
        coalitions.push_back(coalition);
        agent.setCoalition(coalition);
        coalition.setAgent_for_copying(agent);
    }
}

void Simulation::step()
{
    //parties step
    for (Party* party : collectingOffersParties)
    {
        party->step(*this);
    }
    //agents step
    for(Agent& agent : mAgents)
    {
        agent.step(*this);
    }
    
}

bool Simulation::shouldTerminate() const
{

    // TODO implement this method

    
    return true;
}

const Graph& Simulation::getGraph() const
{
    return mGraph;
}

Graph& Simulation::getGraph()
{
    return mGraph;
}

const vector<Agent> &Simulation::getAgents() const
{
    return mAgents;
}

vector<Agent> &Simulation::getAgents()
{
    return mAgents;
}

const Party& Simulation::getParty(int partyId) const
{
    return mGraph.getParty(partyId);
}
Party& Simulation::getParty(int partyId)
{
    return mGraph.getParty(partyId);
}

Coalition& Simulation::getCoalition(int coalitionId)
{
    return coalitions.at(coalitionId);
}

/// This method returns a "coalition" vector, where each element is a vector of party IDs in the coalition.
/// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const vector<vector<int>> Simulation::getPartiesByCoalitions() const
{


    // TODO: you MUST implement this method for getting proper output, read the documentation above.


    return vector<vector<int>>();
}
