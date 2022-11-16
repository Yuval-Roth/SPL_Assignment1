#include "../include/SelectionPolicy.h"
#include "../include/JoinPolicy.h"


EdgeWeightSelectionPolicy::EdgeWeightSelectionPolicy()
{
    
}
EdgeWeightSelectionPolicy* EdgeWeightSelectionPolicy::clone()
{
    return new EdgeWeightSelectionPolicy();
}
Party* EdgeWeightSelectionPolicy::selectParty(list<Party*> & party)
{
    // TODO: Implement this method
    return new Party(0, "temp", 0,new MandatesJoinPolicy());
}



MandatesSelectionPolicy::MandatesSelectionPolicy()
{
    
}
MandatesSelectionPolicy* MandatesSelectionPolicy::clone()
{
    return new MandatesSelectionPolicy();
}
Party* MandatesSelectionPolicy::selectParty(list<Party*>& party)
{
    // TODO: Implement this method
    return new Party(0, "temp", 0,new MandatesJoinPolicy());
}