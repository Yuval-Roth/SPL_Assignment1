#ifndef Agent_h
#define Agent_h


#include <vector>
#include "Graph.h"


class Coalition;
class SelectionPolicy;

class Agent
{
public:
    Agent() = default;
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy, Coalition* );
    int getPartyId() const;
    int getId() const;
    void step(Simulation &);
    void setCoalition(Coalition&);
    Coalition& getCoalition();
    SelectionPolicy* getSelectionPolicy();
private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
    bool alreadySet;

    //Do not delete coalition in this class
    Coalition* coalition;
};
#endif