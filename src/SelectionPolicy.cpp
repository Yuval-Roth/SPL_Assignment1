#include "../include/SelectionPolicy.h"
#include "../include/JoinPolicy.h"


EdgeWeightSelectionPolicy::EdgeWeightSelectionPolicy()
{
    
}

Party* EdgeWeightSelectionPolicy::selectParty(list<Party*> & party)
{
    // TODO: Implement this method
    return new Party(0, "temp", 0,new MandatesJoinPolicy());
}



MandatesSelectionPolicy::MandatesSelectionPolicy()
{
    
}

Party* MandatesSelectionPolicy::selectParty(list<Party*>& party)
{
    // TODO: Implement this method
    return new Party(0, "temp", 0,new MandatesJoinPolicy());
}