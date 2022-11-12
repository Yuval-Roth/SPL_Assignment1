#pragma once

#include <vector>
#include <list>

#include "Graph.h"
#include "Agent.h"

using std::string;
using std::vector;
using std::list;

class Simulation
{
public:
    Simulation(Graph g, vector<Agent> agents);

    void step();
    bool shouldTerminate() const;

    const Graph &getGraph() const;
    const vector<Agent> &getAgents() const;
    const Party &getParty(int partyId) const;
    const vector<vector<int>> getPartiesByCoalitions() const;
    ~Simulation();

private:
    Graph mGraph;
    vector<Agent> mAgents;
    list<Coalition> coalitions;
    int CoalitionIdCounter;
    list<Party&> collectingOffersParties;
};
