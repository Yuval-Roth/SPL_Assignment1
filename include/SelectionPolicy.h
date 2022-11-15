#ifndef SelectionPolicy_h
#define SelectionPolicy_h

#include <list>
using std::list;

#include "Party.h"

// class Party;

class SelectionPolicy
{
    public: 

    virtual Party* selectParty(list<Party*> &) = 0; 
};

// #endif

// #ifndef EdgeWeightSelectionPolicy_h
// #define EdgeWeightSelectionPolicy_h

class EdgeWeightSelectionPolicy: public SelectionPolicy
{
    public:

    EdgeWeightSelectionPolicy();
    Party* selectParty(list<Party*>& party);  
};
// #endif

// #ifndef MandatesSelectionPolicy_h
// #define MandatesSelectionPolicy_h 

class MandatesSelectionPolicy: public SelectionPolicy
{
    public:

    MandatesSelectionPolicy();
    Party* selectParty(list<Party*>& party);
};
#endif
