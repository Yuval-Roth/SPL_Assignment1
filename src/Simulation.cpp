#include "../include/Simulation.h"

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph),
mAgents(agents), coalitions(),CoalitionIdCounter(0),collectingOffersParties() 
{   
    for(Agent agent : mAgents)
    {
        agent.setCoalition(CoalitionIdCounter++);
    }
}

void Simulation::step()
{
    //parties step
    for (int partyId : collectingOffersParties)
    {
        mGraph.getParty_non_const(partyId).step(*this);
    }
    //agents step
    for(Agent agent : mAgents)
    {
        agent.step(*this);
    }
    
}

bool Simulation::shouldTerminate() const
{
    // TODO implement this method
    return true;
}

const Graph &Simulation::getGraph() const
{
    return mGraph;
}

const vector<Agent> &Simulation::getAgents() const
{
    return mAgents;
}

const Party &Simulation::getParty(int partyId) const
{
    return mGraph.getParty(partyId);
}

Coalition& Simulation::getCoalition(int coalitionId)
{
    std::_List_iterator<Coalition> iter ;
    for (iter = coalitions.begin() ; iter->CoalitionId != coalitionId ; iter++){} 
    return *iter;
}

/// This method returns a "coalition" vector, where each element is a vector of party IDs in the coalition.
/// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const vector<vector<int>> Simulation::getPartiesByCoalitions() const
{
    // TODO: you MUST implement this method for getting proper output, read the documentation above.
    return vector<vector<int>>();
}
