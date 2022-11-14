#ifndef JoinPolicy_h
#define JoinPolicy_h

class JoinPolicy {
    public:
        virtual void selectParty(const list<Party> &) const = 0;
};

class MandatesJoinPolicy : public JoinPolicy {};

class LastOfferJoinPolicy : public JoinPolicy {};
#endif