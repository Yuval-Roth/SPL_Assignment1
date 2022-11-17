#include "../include/SelectionPolicy.h"
#include "../include/JoinPolicy.h"



EdgeWeightSelectionPolicy::EdgeWeightSelectionPolicy()
{
    
}

Party* EdgeWeightSelectionPolicy::selectParty(list<Party*> & party)
{
    // TODO: Implement this method
    for(Party* mParty : party ){

    }
    return new Party(0, "temp", 0,new MandatesJoinPolicy());
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