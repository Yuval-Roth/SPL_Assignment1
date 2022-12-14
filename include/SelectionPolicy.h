#ifndef SelectionPolicy_h
#define SelectionPolicy_h

#include <list>
using std::list;

#include "Party.h"

class Graph;

class SelectionPolicy
{
    public: 

    virtual SelectionPolicy* clone() const =0;
    virtual Party* selectParty(list<Party*>& party, Graph& graph, int partyId) = 0; 
    virtual ~SelectionPolicy() {};

};

// #endif

// #ifndef EdgeWeightSelectionPolicy_h
// #define EdgeWeightSelectionPolicy_h

class EdgeWeightSelectionPolicy: public SelectionPolicy
{
    public:

    EdgeWeightSelectionPolicy() = default;
    SelectionPolicy* clone() const;
    Party* selectParty(list<Party*>& party, Graph& graph, int partyId);  
};
// #endif

// #ifndef MandatesSelectionPolicy_h
// #define MandatesSelectionPolicy_h 

class MandatesSelectionPolicy: public SelectionPolicy
{
    public:

    MandatesSelectionPolicy() = default;
    SelectionPolicy* clone() const;
    Party* selectParty(list<Party*>& party, Graph& graph, int partyId);
};
#endif
