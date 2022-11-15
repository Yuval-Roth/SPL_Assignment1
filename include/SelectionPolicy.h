#ifndef SelectionPolicy_h
#define SelectionPolicy_h

#include <list>
using std::list;

class Party;

class SelectionPolicy
{
    public: 

    virtual Party* selectParty(const list<Party*> &) const = 0; 
};

#endif

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
