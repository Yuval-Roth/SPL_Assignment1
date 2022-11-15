#include "../include/JoinPolicy.h"
#include "../include/Coalition.h"

Coalition* MandatesJoinPolicy::selectCoalition(list<Coalition>& coalition)
{
    return new Coalition(0);
}


Coalition* LastOfferJoinPolicy::selectCoalition(list<Coalition>& coalition)
{
    return new Coalition(0);
}