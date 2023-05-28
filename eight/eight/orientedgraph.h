    #ifndef ORIENTEDGRAPH_H
#define ORIENTEDGRAPH_H
#include"matrix.h"

class OrientedGraph
{
public:
    OrientedGraph(QByteArray &content);
    OrientedGraph();
    ~OrientedGraph();
    Matrix* m;
    OrientedGraph(const OrientedGraph& other) : m(new Matrix(*other.m)) {}
    OrientedGraph& operator=(const OrientedGraph& other);
};

#endif // ORIENTEDGRAPH_H
