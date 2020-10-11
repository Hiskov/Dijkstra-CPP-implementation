#include <iostream>
#include "Graph.h"
#include "ShortestPath.h"

using namespace std;

int main()
{
    int dens_num = 2;   //number of densities
    float densities[dens_num] = {0.2, 0.4}; //the densities
	int node_num = 50;  //number of node

	cout << "For a graph of " << node_num << " nodes a distance range of 1.0 to 10.0:" << endl << endl;
	for(int i = 0 ; i < dens_num ; i++) //for each density
	{
		float sum = 0;
		int reachable_node = 0; //number of reachable node from the node 0
		Graph graph(node_num, densities[i]);

		for(int x = 1; x < node_num; x++) //for each other node x
		{
			int path_size = ShortestPath::pathSize(graph, 0, x);
			if (path_size != INF)   //path_size = INF ==> no path from node 0 to node x
			{
				sum += path_size;
				reachable_node++;
			}
		}
		cout << "For a graph with density " << densities[i]
             << ", the average path length is " << sum/reachable_node << endl; //no reachable node ==> "omit that value from the average"
	}

	return 0;
}
