#ifndef EdgeWeightSelectionPolicy_h
#define EdgeWeightSelectionPolicy_h

#include "SelectionPolicy.h"

class EdgeWeightSelectionPolicy: public SelectionPolicy
{
    public:

    EdgeWeightSelectionPolicy();
    Party* selectParty(const list<Party*>& party) const;  
};
#endif