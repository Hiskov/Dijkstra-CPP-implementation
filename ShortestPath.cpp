#include "ShortestPath.h"
#include "PriorityQueue.h"


/*-------------------------------------------------------------------------
           Implementation of Dijkstra algorithm
[IN]
- The graph is passed by reference
- We want the shortest path from source to target

[OUT]
- dist is the distance of this shortest path
- prev is the list of predecessor: prev[x]=y ==> y is the predecessor of x
---------------------------------------------------------------------------*/
void ShortestPath::dijkstra(Graph &graph, int source, int target, int& dist, vector<int>& prev)
{
    PriorityQueue Q;         //priority queue
    int graph_size;          //size of the graph
    vector<int> all_dist;    //all_dist[x]=d ==> d is the distance from source to x
    int y = -1;              //current processed node
    vector<int> neighbors_y; //neighbors of y
    int z;                   //current processed neighbor of y
    int alt;                 //current distance from source to z


    /*INITIALIZATION*/
    graph_size = graph.getNodeNumber();
    all_dist = vector<int>(graph_size);
    all_dist[source] = 0;
    prev = vector<int>(graph_size);

    for(int x = 0; x < graph_size ; x++)  //for each node x in the graph
    {
        if(x != source){
            all_dist[x] = INF;
            prev[x] = UNDEFINED;
        }
        Q.addWithPriority(x, all_dist[x]);
    }


    /*MAIN LOOP*/
    while(!Q.isEmpty() && y != target)
    {
        y = Q.extractMin();

        if(y != target){
            neighbors_y = graph.neighbors(y);

            //for each neighbor z of y
            for (vector<int>::iterator it = neighbors_y.begin() ; it != neighbors_y.end(); ++it){
                z = *it;
                alt = all_dist[y] + graph.getEdgeValue(y, z);
                if(alt < all_dist[z]){
                    all_dist[z] = alt;
                    prev[z] = y;
                    Q.decreasePriority(z, alt);
                }
            }
        }
    }
    dist = all_dist[target];
}



/*------------------------------------------------------------------------------------------------------
 Find shortest path between source-target and returns the sequence of nodes representing shortest path
--------------------------------------------------------------------------------------------------------*/
vector<int> ShortestPath::path(Graph &graph, int source, int target)
{
    int dist; //unused distance
    vector<int> target_path;  //shortest path between source-target
    vector<int> prev;   //the list of predecessor

    ShortestPath::dijkstra(graph, source, target, dist, prev);

    //Read the shortest path from source to target by reverse iteration
    //with the list of predecessor
    int u = target;
    if(prev[u] != UNDEFINED || u == source) //if the node is reachable
    {
        while(u != UNDEFINED){  //Construct the shortest path
            target_path.insert(target_path.begin(), u); //insert node into beginning
            u = prev[u];    //Traverse from target to source
        }
    }
    return target_path;
}


/*------------------------------------------------------------------------------------------------------
                        Return the path cost associated with the shortest path.
--------------------------------------------------------------------------------------------------------*/
int ShortestPath::pathSize(Graph &graph, int source, int target)
{
    int dist;
    vector<int> prev;   //unused list of predecessor
    ShortestPath::dijkstra(graph, source, target, dist, prev);
    return dist;
}


