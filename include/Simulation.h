#ifndef Simulation_h
#define Simulation_h

#include <vector>
#include <list>

#include "Agent.h"
#include "Coalition.h"

using std::string;
using std::vector;
using std::list;

class Graph;


class Simulation
{
public:
    Simulation(Graph g, vector<Agent> agents);

    void step();
    bool shouldTerminate() const;

    const Graph &getGraph() const;
    Graph &getGraph_non_const();
    const vector<Agent> &getAgents() const;
    const Party &getParty(int partyId) const;
    const vector<vector<int>> getPartiesByCoalitions() const;
    Coalition& getCoalition(int coalitionId); 
    ~Simulation();

private:
    Graph mGraph;
    vector<Agent> mAgents;
    list<Coalition*> coalitions;
    int CoalitionIdCounter;
    list<Party*> collectingOffersParties;
    // Party* parties;
};
#endif