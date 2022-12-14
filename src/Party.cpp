#include "../include/Party.h"
#include "../include/Simulation.h"
#include "../include/Graph.h"
#include "../include/JoinPolicy.h"

//constructors

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name),
 mMandates(mandates), mJoinPolicy(jp), mState(Waiting), timer(1), offers(){}

Party::Party(const Party& other): mId(other.mId), mName(other.mName), mMandates(other.mMandates),
 mJoinPolicy(other.mJoinPolicy->clone()), mState(other.mState), timer(other.timer), offers(other.offers){}

Party& Party::operator=(const Party& other)
{   
    if(this != &other){
        delete mJoinPolicy;
    }
    mId = other.mId;
    mName = other.mName;
    mMandates = other.mMandates;
    mJoinPolicy = other.mJoinPolicy->clone();
    mState = other.mState;
    timer = other.timer;
    offers = other.offers;

    return *this;
}

Party::Party(Party&& rvalue) : Party(rvalue.mId,rvalue.mName,rvalue.mMandates,rvalue.mJoinPolicy)
{
    rvalue.mJoinPolicy = NULL;
}

Party& Party::operator=(Party&& rvalue)
{
    mId = rvalue.mId;
    mName = rvalue.mName;
    mMandates = rvalue.mMandates;
    delete mJoinPolicy;
    mJoinPolicy = rvalue.mJoinPolicy;

    rvalue.mJoinPolicy = NULL;
    return *this;
}

//======================================================================

State Party::getState() const
{
    return mState;
}

void Party::setState(State state)
{
    mState = state;
}

int Party::getMandates() const
{
    return mMandates;
}

const string & Party::getName() const
{
    return mName;
}
int Party::getId() const
{
    return mId;
}
void Party::step(Simulation &sim)
{
    if (mState == CollectingOffers)
    {
        if (timer == 3)
        {
            //Do not delete chosenCoalition
            Coalition* chosenCoalition = mJoinPolicy->selectCoalition(offers,sim.getGraph());
            chosenCoalition->addParty(mId, sim);
            sim.announceJoined();
            mState = State::Joined;
            // timer++;
        }
        else
        {
            timer++;
        }
    }
}

void Party::acceptOffer(Coalition& coalition,Simulation& sim)
{
    if(mState == State::Waiting)
    {
        mState = State::CollectingOffers;
        sim.getCollectingOffersParties().push_front(this);
    } 
    offers.push_front(&coalition);    
}

Party::~Party()
{
    delete mJoinPolicy;
}
