#ifndef Agent_h
#define Agent_h


#include <vector>
#include "Graph.h"


class Coalition;
class SelectionPolicy;

class Agent
{
public:

    //Constructors

    
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy, Coalition* coalition);
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy); 
    Agent(const Agent& other); 
    Agent& operator=(const Agent& other);
    Agent(Agent&& rvalue);
    Agent& operator=(Agent&& other);
    Agent() = default;

    //methods

    int getPartyId() const;
    int getId() const;
    void step(Simulation &);
    void setCoalition(Coalition&);
    Coalition& getCoalition();
    SelectionPolicy* getSelectionPolicy();

    ~Agent();
    
private:

    //constructors
    
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy,bool alreadySet,Coalition* coalition);

    //fields

    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
    bool alreadySet;    
    Coalition* coalition; //Do not delete coalition field in this class
};
#endif