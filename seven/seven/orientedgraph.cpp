#include "orientedgraph.h"

    OrientedGraph::OrientedGraph(QByteArray &content)
    {
        m = new Matrix(content);
    }

    OrientedGraph::~OrientedGraph()
    {
        delete m;
    }


    OrientedGraph& OrientedGraph::operator=(const OrientedGraph& other) {
        if (this == &other) {
            return *this;
        }
        delete m;
        m = new Matrix(*other.m);
        return *this;
    }
