#ifndef MandatesSelectionPolicy_h
#define MandatesSelectionPolicy_h 

#include "SelectionPolicy.h"

class MandatesSelectionPolicy: public SelectionPolicy
{
    public:

    MandatesSelectionPolicy();
    Party* selectParty(const list<Party*>& party) const;
};
#endif