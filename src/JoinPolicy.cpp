#include "../include/JoinPolicy.h"
#include "../include/Coalition.h"


MandatesJoinPolicy::MandatesJoinPolicy()
{

}
Coalition* MandatesJoinPolicy::selectCoalition(list<Coalition>& coalition)
{
    return new Coalition(0);
}


LastOfferJoinPolicy::LastOfferJoinPolicy()
{
    
}
Coalition* LastOfferJoinPolicy::selectCoalition(list<Coalition>& coalition)
{
    return new Coalition(0);
}