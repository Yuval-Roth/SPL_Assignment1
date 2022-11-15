#include "../include/Party.h"
#include "../include/Simulation.h"
#include "../include/Graph.h"
#include "../include/JoinPolicy.h"

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name),
 mMandates(mandates), mJoinPolicy(jp), mState(Waiting), timer(0), offers()
{
    // You can change the implementation of the constructor, but not the signature!
}

Party::Party(const Party& other): mId(other.mId), mName(other.mName), mMandates(other.mMandates),
 mJoinPolicy(other.mJoinPolicy), mState(other.mState), timer(other.timer), offers(other.offers)
{
    //TODO: Implement clone for the join policy and offers
}
Party& Party::operator=(const Party& other)
{   
    return *this;
}
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
void Party::step(Simulation &s)
{
    if (mState == CollectingOffers)
    {
        if (timer == 3)
        {
            //Do not delete chosenCoalition
            Coalition* chosenCoalition = mJoinPolicy->selectCoalition(offers);
            chosenCoalition->addParty(mId);
        }
        else
        {
            timer++;
        }
    }
}

void Party::acceptOffer(Coalition& coalition)
{
    //TODO: Implement this method
}
// Party::~Party()
// {
//     delete mJoinPolicy;
// }