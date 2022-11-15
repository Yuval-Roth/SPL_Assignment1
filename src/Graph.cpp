#include "../include/Graph.h"
#include <stdexcept>

Graph::Graph(vector<Party> vertices, vector<vector<int>> edges) : mVertices(vertices), mEdges(edges) 
{
    // You can change the implementation of the constructor, but not the signature!
}

int Graph::getMandates(int partyId) const
{
    return mVertices[partyId].getMandates();
}

int Graph::getEdgeWeight(int v1, int v2) const
{
    return mEdges[v1][v2];
}

int Graph::getNumVertices() const
{
    return mVertices.size();
}

const Party &Graph::getParty(int partyId) const
{
    return mVertices[partyId];
}
Party &Graph::getParty(int partyId)
{

    return mVertices[partyId];
    // if(partyId > getNumVertices()) throw std::runtime_error("invalid partyId");

    // std::_List_iterator<Party> iter ;
    // for (iter = mVertices.begin() ; iter->getId() != partyId ; iter++){ }
    // return *iter;
}