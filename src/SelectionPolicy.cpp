#include "../include/SelectionPolicy.h"
#include "../include/JoinPolicy.h"



EdgeWeightSelectionPolicy::EdgeWeightSelectionPolicy()
{
    
}

Party* EdgeWeightSelectionPolicy::selectParty(list<Party*> & party, Graph graph)
{
    // TODO: Implement this method
    Graph& graph = graph;
    int maxVal = 0;
    Party* chosenParty = 0;

    for(Party* currParty : party ){
        if (graph.getEdgeWeight(currParty->getId , agent.getId()) > maxVal) 
        {
            maxVal = graph.getEdgeWeight(currParty->getId , agent.getId());
            chosenParty = currParty;
        }
        
    }
    return chosenParty;
}



MandatesSelectionPolicy::MandatesSelectionPolicy()
{
    
}

Party* MandatesSelectionPolicy::selectParty(list<Party*>& party)
{
    // TODO: Implement this method
    int maxVal = 0;
    Party* chosenParty = 0;
    
    for(Party* currParty : party){
        if (currParty->getMandates() > maxVal)
        {
            maxVal = currParty->getMandates();
            chosenParty = currParty;
        }   
    }
    return chosenParty;
}