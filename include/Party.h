
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

    //constructors

    Party(int id, string name, int mandates, JoinPolicy * policy); 
    Party(const Party&);
    Party& operator=(const Party&);
    Party(Party&& rvalue);
    Party& operator=(Party&& rvalue);
    Party() = default;



    //methods

    void step(Simulation &s);
    
    const string &getName() const;
    State getState() const;
    void setState(State state);
    int getMandates() const;
    int getId() const;
    
    void acceptOffer(Coalition&,Simulation&); //agent give the party an offer
    

    ~Party();
private:

    //fields

    int mId;
    string mName;
    int mMandates;
    JoinPolicy *mJoinPolicy;
    State mState;
    int timer;
    list<Coalition*> offers;
};
#endif
