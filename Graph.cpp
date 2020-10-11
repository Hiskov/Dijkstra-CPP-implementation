#include "Graph.h"
#include <ctime>
#include <random>


//generate a random float between 0 and 1
inline float randomFloat(){return (rand() % 10)/10.0;}



/*-----------------------------------------------------
Constructor with the size of the graph and the density
     with values between value_min and value_max
-------------------------------------------------------*/
Graph::Graph(int size, float density, int value_min, int value_max):
    edge_num(0),
    node_num(size)
{
    srand(time(0)); //seed init
    int value;  //value of the created edge
    matrix = vector<vector<int>>(size, vector<int>(size));
    for(int i = 0 ; i < size ; i++)
    {
        for(int j = i+1 ; j < size ; j++) //no directed edge ==> we treat half of the matrix
        {
            if(randomFloat() < density){
                value = value_min + value_max*randomFloat();
                addEdge(i, j, value);
                edge_num++;
            }
        }
    }
}



/*-----------------------------------------------------
                Return the number of node
-------------------------------------------------------*/
int Graph::getNodeNumber()
{
    return node_num;
}


/*-----------------------------------------------------
                Return the number of Edge
-------------------------------------------------------*/
int Graph::getEdgeNumber()
{
    return edge_num;
}


/*-----------------------------------------------------
 Tests whether there is an edge from node x to node y
-------------------------------------------------------*/
bool Graph::adjacent(int x, int y)
{
    return matrix[x][y] > 0;    //0 ==> false, >0 ==> true
}


/*--------------------------------------------------------
 Lists all nodes y such that there is an edge from x to y
----------------------------------------------------------*/
vector<int> Graph::neighbors(int x)
{
    vector<int> neigh;
    for(int y = 0 ; y < node_num ; y++)
    {
        if(matrix[x][y] > 0)//there is an edge from x to y
        {
            neigh.push_back(y); //we add y to the list
        }
    }
    return neigh;
}


/*--------------------------------------------------------
          Adds the edge from x to y with value v
----------------------------------------------------------*/
void Graph::addEdge(int x, int y, int v)
{
    matrix[x][y] = v;
    matrix[y][x] = v; //no directed edge ==> symmetric matrix
}


/*--------------------------------------------------------
               Removes the edge from x to y
----------------------------------------------------------*/
void Graph::deleteEdge(int x, int y)
{
    matrix[x][y] = 0;
}



/*--------------------------------------------------------
     Returns the value associated to the edge (x,y)
----------------------------------------------------------*/
int Graph::getEdgeValue(int x, int y)
{
    return matrix[x][y];
}



//no particular destructor
Graph::~Graph()
{

}
