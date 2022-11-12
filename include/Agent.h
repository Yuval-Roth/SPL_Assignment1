#ifndef Agent_h
#define Agent_h

#include <vector>
#include "Graph.h"


class SelectionPolicy;

class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);

    int getPartyId() const;
    int getId() const;
    void step(Simulation &);
    void setCoalition(int coalitionId);
    int getCoalition();
private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
    bool alreadySet;
    int coalitionId;
};
#endif