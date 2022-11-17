
#ifndef State_enum
#define State_enum
enum State
{
    Waiting,
    CollectingOffers,
    Joined
};
#endif

#ifndef Party_h
#define Party_h
#include <string>
#include <list>

using std::string;
using std::list;

class JoinPolicy;
class Simulation;
class Coalition;

class Party
{
public:
    Party();
    Party(int id, string name, int mandates, JoinPolicy * policy); 
    Party(const Party&);
    Party& operator=(const Party&);
    State getState() const;
    void setState(State state);
    int getMandates() const;
    void step(Simulation &s);
    const string &getName() const;
    int getId() const;
    void acceptOffer(Coalition&); //agent give the party an offer
    

    // ~Party();
private:
    int mId;
    string mName;
    int mMandates;
    JoinPolicy *mJoinPolicy;
    State mState;
    int timer;
    list<Coalition*> offers;
};
#endif
