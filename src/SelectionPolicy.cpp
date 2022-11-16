#include "../include/SelectionPolicy.h"
#include "../include/JoinPolicy.h"


SelectionPolicy* EdgeWeightSelectionPolicy::clone()
{
    return new EdgeWeightSelectionPolicy();
}
Party* EdgeWeightSelectionPolicy::selectParty(list<Party*> & party)
{
    // TODO: Implement this method
    return new Party(0, "temp", 0,new MandatesJoinPolicy());
}



SelectionPolicy* MandatesSelectionPolicy::clone()
{
    return new MandatesSelectionPolicy();
}
Party* MandatesSelectionPolicy::selectParty(list<Party*>& party)
{
    // TODO: Implement this method
    return new Party(0, "temp", 0,new MandatesJoinPolicy());
