//https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/
// A C++ program for Prim's Minimum
// Spanning Tree (MST) algorithm. The program is
// for adjacency matrix representation of the graph

#include <bits/stdc++.h>
using namespace std;

// Number of vertices in the graph
#define V 7

// A utility function to find the vertex with
// minimum key value, from the set of vertices
// not yet included in MST
int minKey(int key[], bool mstSet[])
{
	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}

// A utility function to print the
// constructed MST stored in parent[]
void printMST(int parent[], int graph[V][V])
{
	cout << "Edge \tWeight\n";
	for (int i = 1; i < V; i++)
		cout << parent[i] << " - " << i << " \t"
			<< graph[i][parent[i]] << " \n";
}

// Function to construct and print MST for
// a graph represented using adjacency
// matrix representation
void primMST(int graph[V][V])
{
	// Array to store constructed MST
	int parent[V];

	// Key values used to pick minimum weight edge in cut
	int key[V];

	// To represent set of vertices included in MST
	bool mstSet[V];

	// Initialize all keys as INFINITE
	for (int i = 0; i < V; i++)
		key[i] = INT_MAX, mstSet[i] = false;

	// Always include first 1st vertex in MST.
	// Make key 0 so that this vertex is picked as first
	// vertex.
	key[0] = 0;

	// First node is always root of MST
	parent[0] = -1;

	// The MST will have V vertices
	for (int count = 0; count < V - 1; count++) {
		
		// Pick the minimum key vertex from the
		// set of vertices not yet included in MST
		int u = minKey(key, mstSet);

		// Add the picked vertex to the MST Set
		mstSet[u] = true;

		// Update key value and parent index of
		// the adjacent vertices of the picked vertex.
		// Consider only those vertices which are not
		// yet included in MST
		for (int v = 0; v < V; v++)

			// graph[u][v] is non zero only for adjacent
			// vertices of m mstSet[v] is false for vertices
			// not yet included in MST Update the key only
			// if graph[u][v] is smaller than key[v]
			if (graph[u][v] && mstSet[v] == false
				&& graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
	}

	// Print the constructed MST
	printMST(parent, graph);
}

// Driver's code
int main()
{
	int graph[V][V] = { 
                            { 0, 0, 2703, 189, 0, 1257, 868 },//BOS
                            { 0, 0, 1465,  0, 1234, 1124, 803 },//DFW
                            { 2703, 1465, 0, 0, 338, 0, 1847 },//JFK
                            { 189, 0,0,0, 0, 1093, 743 }, // SFO
                            { 0,1234,338,0,0,2341,0 },//LAX
                            { 1257,1124,0,1093,2341,0,0},//MIA
                            { 868,803,1847,743,0,0,0}};//ORD

	// Print the solution
        cout<<"\nPrim's Spanning Tree\n";
	primMST(graph);
        int weight = graph[6][1] + graph[1][4];
        cout<<"ORD to DFW = "<<graph[6][1]<<endl;
        cout<<"DFW to LAX = "<<graph[1][4]<<endl;
        cout<<"ORD to LAX = "<<weight<<endl;
        cout<<"Hand written analysis expected: 2037\n\n";
        
        
        weight = graph[3][6] + graph[6][2];
        cout<<"JFK to ORD = "<<graph[3][6]<<endl;
        cout<<"ORD to SFO = "<<graph[6][2]<<endl;
        cout<<"JFK to SFO = "<<weight<<endl<<endl;
        cout<<"Hand written analysis expected: 2590\n";
	return 0;
}

// This code is contributed by rathbhupendra
//int graph[V][V] = { { 0, 0, 2703, 189, 0, 1257, 868 },
//                            { 0, 0, 1465,  0, 1234, 1124, 803 },
//                            { 2703, 1465, 0, 0, 338, 0, 1847 },
//                            { 189, 0,0,0, 0, 1093, 743 },
//                            { 0,1234,338,0,0,2341,0 },
//                            { 1257,1124,0,1093,2341,0,0},
//                            { 868,803,1847,743,0,0,0}};