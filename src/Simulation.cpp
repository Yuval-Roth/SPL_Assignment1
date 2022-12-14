#include "../include/Simulation.h"
#include "../include/Graph.h"

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph),
mAgents(agents), coalitions(),CoalitionIdCounter(0),collectingOffersParties(),joinedParties(mAgents.size())
{   
    for(Agent& agent : mAgents)
    {
        Coalition* coalition = new Coalition(CoalitionIdCounter++,mGraph.getParty(agent.getPartyId()));
        agent.setCoalition(*coalition);
        coalition->setAgent_for_copying(agent);
        coalitions.push_back(coalition);
    }
}

void Simulation::step()
{

    //parties step
    std::list<Party*>::iterator iter;
    iter = collectingOffersParties.begin();
    while ((collectingOffersParties.empty() == false) & (iter != collectingOffersParties.end()))
    {
        Party* current = (*iter);
        auto temp = iter++;
        if(current->getState() == State::Joined)
        {
            collectingOffersParties.erase(temp);
        }        
        else current->step(*this);      
    }
    //agents step
    for(Agent& agent : mAgents)
    {
        agent.step(*this);
    }
    
}

bool Simulation::shouldTerminate() const
{
    if (joinedParties == mGraph.getNumVertices()) return true;
    for(Coalition* coalition : coalitions)
    {
        if(coalition->getMandatesCount() >= 61) return true;
    }
    return false;
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
    return *coalitions.at(coalitionId);
}
void Simulation::announceJoined()
{
    joinedParties++;
}

/// This method returns a "coalition" vector, where each element is a vector of party IDs in the coalition.
/// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const vector<vector<int>> Simulation::getPartiesByCoalitions() const
{
    auto output = vector<vector<int>>();

    for(const Coalition* coalition : coalitions)
    {
        output.push_back(vector<int>());
        for(int member : coalition->getMembers())
        {
            output[coalition->CoalitionId].push_back(member);
        }
    }   
    return output;
}
list<Party*>& Simulation::getCollectingOffersParties()
{
    return collectingOffersParties;
}

Simulation::~Simulation()
{
    for(Coalition* coal : coalitions)
    {
        delete coal;
    }
}
