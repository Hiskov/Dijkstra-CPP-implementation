/*--------------------------------------------------------------------------
ShortestPath class that implements the mechanics of Dijkstra’s algorithm

It's just a class that encapsulate methods so we don't want this class
to be instantiated (static declaration)
--------------------------------------------------------------------------*/


#ifndef SHORTESTPATH_H
#define SHORTESTPATH_H

#include "Graph.h"
#include <cstdlib>

const int INF = 9999999; //integer representing infinity
const int UNDEFINED = -1; //undefined value for a node with no predecessor

class ShortestPath
{
    public:
        static vector<int> path(Graph &graph, int source, int target);
        static int pathSize(Graph &graph, int source, int target);

    private:
        static void dijkstra(Graph &graph, int source, int target, int& dist, vector<int>& prev);
        ShortestPath(); //static class ==> private constructor (no instances)

};

#endif // SHORTESTPATH_H
