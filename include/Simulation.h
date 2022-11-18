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
    Graph &getGraph();
    const vector<Agent> &getAgents() const;
    vector<Agent> &getAgents();
    const Party &getParty(int partyId) const;
    Party &getParty(int partyId);
    const vector<vector<int>> getPartiesByCoalitions() const;
    Coalition& getCoalition(int coalitionId); 
    void announceJoined();
    ~Simulation();
    list<Party*> collectingOffersParties;

private:
    Graph mGraph;
    vector<Agent> mAgents;
    vector<Coalition*> coalitions;
    int CoalitionIdCounter;

    //Do not delete the parties in this list
    int joinedParties;
};
#endif