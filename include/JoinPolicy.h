#ifndef JoinPolicy_h
#define JoinPolicy_h

#include "Coalition.h"
#include "Party.h"

class JoinPolicy
 {
    public:

    virtual Coalition* selectCoalition(list<Coalition*> &)= 0;
    virtual JoinPolicy* clone() = 0;
    virtual ~JoinPolicy() {};
};
// #endif


// #ifndef MandatesJoinPolicy_h
// #define MandatesJoinPolicy_h
class MandatesJoinPolicy : public JoinPolicy 
{
    public:

    MandatesJoinPolicy() = default;
    JoinPolicy* clone();
    Coalition* selectCoalition(list<Coalition*> &);
    ~MandatesJoinPolicy() = default;
};
// #endif

// #ifndef LastOfferJoinPolicy_h
// #define LastOfferJoinPolicy_h
class LastOfferJoinPolicy : public JoinPolicy
{
    public:

    LastOfferJoinPolicy() = default;
    JoinPolicy* clone();
    Coalition* selectCoalition(list<Coalition*> &);
    ~LastOfferJoinPolicy() = default;
};
#endif