#include "../include/SelectionPolicy.h"


EdgeWeightSelectionPolicy::EdgeWeightSelectionPolicy()
{
    
}

Party* EdgeWeightSelectionPolicy::selectParty(const list<Party*> & party)
{
    // TODO: Implement this method
    return new Party(0, "temp", 0,new EdgeWeightSelectionPolicy());
}



MandatesSelectionPolicy::MandatesSelectionPolicy()
{
    
}

Party* MandatesSelectionPolicy::selectParty(const list<Party*>& party)
{
    // TODO: Implement this method
    return new Party(0, "temp", 0,new MandatesSelectionPolicy());
}