#include "../include/SelectionPolicy.h"
#include "../include/JoinPolicy.h"

SelectionPolicy* EdgeWeightSelectionPolicy::clone() const
{
    return new EdgeWeightSelectionPolicy();
}

Party* EdgeWeightSelectionPolicy::selectParty(list<Party*> & parties, Graph& graph, int partyId)
{
    int maxVal = 0;
    Party* chosenParty = 0;

    for(Party* currParty : parties ){
        int eWeight = graph.getEdgeWeight(currParty->getId (), partyId);
        if (eWeight >= maxVal) 
        {
            if(eWeight == maxVal)
            {
                if(eWeight > graph.getEdgeWeight(chosenParty->getId (), partyId))
                    chosenParty = currParty;    
            }
            else
            {
                maxVal = graph.getEdgeWeight(currParty->getId() , partyId);
                chosenParty = currParty;
            }         
        }     
    }
    return chosenParty;
}

SelectionPolicy* MandatesSelectionPolicy::clone() const
{
    return new MandatesSelectionPolicy();
}
Party* MandatesSelectionPolicy::selectParty(list<Party*>& parties, Graph& graph, int partyId)
{
    int maxVal = 0;
    Party* chosenParty = 0;
    
    for(Party* currParty : parties){
        int currMandates = currParty->getMandates();
        if (currMandates >= maxVal)
        {
            if(currMandates == maxVal)
            {
                if(currParty->getId() < chosenParty->getId())
                    chosenParty = currParty;    
            }
            else{
                maxVal = currParty->getMandates();
                chosenParty = currParty;
            }
            
        }   
    }
    return chosenParty;
}