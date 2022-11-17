#include "../include/SelectionPolicy.h"
#include "../include/JoinPolicy.h"

SelectionPolicy* EdgeWeightSelectionPolicy::clone()
{
    return new EdgeWeightSelectionPolicy();
}

Party* EdgeWeightSelectionPolicy::selectParty(list<Party*> & parties, Graph graph, int partyId)
{
    Graph& graph = graph;
    int maxVal = 0;
    Party* chosenParty = 0;

    for(Party* currParty : parties ){
        if (graph.getEdgeWeight(currParty->getId (), partyId)> maxVal) 
        {
            maxVal = graph.getEdgeWeight(currParty->getId() , partyId);
            chosenParty = currParty;
        }
        
    }
    return chosenParty;
}

SelectionPolicy* MandatesSelectionPolicy::clone()
{
    return new MandatesSelectionPolicy();
}
Party* MandatesSelectionPolicy::selectParty(list<Party*>& parties)
{
    int maxVal = 0;
    Party* chosenParty = 0;
    
    for(Party* currParty : parties){
        if (currParty->getMandates() > maxVal)
        {
            maxVal = currParty->getMandates();
            chosenParty = currParty;
        }   
    }
    return chosenParty;
}