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

class MandatesSelectionPolicy: public SelectionPolicy
{
    public:
    MandatesSelectionPolicy();

    Party& selectParty(const list<Party>& party)
    {
        return *(new Party(0, "temp", 0,new EdgeWeightSelectionPolicy()));
    }
};

class EdgeWeightSelectionPolicy: public SelectionPolicy
{
    public:
    EdgeWeightSelectionPolicy();
    Party& selectParty(const list<Party>& party)
    {
        return *(new Party(0, "temp", 0,new EdgeWeightSelectionPolicy()));
    }
};