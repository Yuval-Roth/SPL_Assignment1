#ifndef SelectionPolicy_h
#define SelectionPolicy_h

#include <list>
using std::list;

class Party;

class SelectionPolicy
{
    public: 

    virtual Party& selectParty(const list<Party> &) const = 0;
};

#endif

class MandatesSelectionPolicy: public SelectionPolicy{ };

class EdgeWeightSelectionPolicy: public SelectionPolicy{ };