#include "../include/MandatesSelectionPolicy.h"

Party* MandatesSelectionPolicy::selectParty(const list<Party*>& party)
{
    // TODO: Implement this method
    return new Party(0, "temp", 0,new MandatesSelectionPolicy());
}