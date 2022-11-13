#include "../include/Party.h"

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting) 
{
    // You can change the implementation of the constructor, but not the signature!
}
Party::Party(const Party& other): mId(other.mId), mName(other.mName), mMandates(other.mMandates), mJoinPolicy(other.mJoinPolicy), mState(other.mState)
{
    //TODO: Implement clone for the join policy
}
Party Party::operator=(const Party& other)
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

void Party::step(Simulation &s)
{
    // TODO: implement this method
}
// Party::~Party()
// {
//     delete mJoinPolicy;
// }