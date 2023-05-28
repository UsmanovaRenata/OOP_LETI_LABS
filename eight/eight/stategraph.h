#ifndef STATEGRAPH_H
#define STATEGRAPH_H

#include "orientedgraph.h"

class StateGraph : public OrientedGraph
{
public:
    StateGraph(QByteArray& content, int active) : OrientedGraph(content), active(active) {}
    ~StateGraph() {}
    int active;
};

#endif // STATEGRAPH_H
