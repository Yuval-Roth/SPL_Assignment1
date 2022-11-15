#ifndef JoinPolicy_h
#define JoinPolicy_h

#include "Coalition.h"
#include "Party.h"

class JoinPolicy
 {
    public:

    virtual Coalition* selectCoalition(list<Coalition*> &)= 0;
};
// #endif


// #ifndef MandatesJoinPolicy_h
// #define MandatesJoinPolicy_h
class MandatesJoinPolicy : public JoinPolicy 
{
    public:

    MandatesJoinPolicy();
    Coalition* selectCoalition(list<Coalition*> &);
};
// #endif

// #ifndef LastOfferJoinPolicy_h
// #define LastOfferJoinPolicy_h
class LastOfferJoinPolicy : public JoinPolicy
{
    public:

    LastOfferJoinPolicy();
    Coalition* selectCoalition(list<Coalition*> &);
};
#endif