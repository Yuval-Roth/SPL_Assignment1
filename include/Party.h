#ifndef Party_h
#define Party_h
#include <string>

using std::string;

class JoinPolicy;
class Simulation;

enum State
{
    Waiting,
    CollectingOffers,
    Joined
};

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
    void acceptOffer(int); //agent give the party an offer
    int getId(){} const;

    // ~Party();
private:
    int mId;
    string mName;
    int mMandates;
    JoinPolicy *mJoinPolicy;
    State mState;
    int timer;
    list<int> offers;
};
#endif