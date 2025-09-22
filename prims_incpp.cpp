#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// prims algorithm  (GREEDY ALGORITHM)

/* we need :
    Selection func ==> to select right vertex ==> minKey()
    Feasibility func ==> to check the condition ==> prims()
     */

// FUNCTOIN TO SELECT THE RIGHT NEXT VERTEX IN MST
int minKey(vector<int> &key, vector<bool> &mstSet)
{
    // key will have the least value of edge weight that has been found
    // mstSet will have bool values showing if a vertex is included in the mst

    // initialize a minimum edge value to infinity for comparing with all the edges
    int min = INT_MAX;
    int min_index = -1;
    int V = mstSet.size();
    for (int v = 0; v < V; v++)
    {
        if (mstSet[v] == false && key[v] < min)
        {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

// FUNCTION TO CHECK THE CONDITIONS
void prims(vector<vector<int>> &graph)
{

    // define parameters
    int V = graph.size();
    vector<int> key(V, INT_MAX);   // stores the least weight value
    vector<int> parent(V, -1);     // stores index of the vertex corresponding to the selected edge
    vector<bool> mstSet(V, false); // for including a vertex in an Mst

    // initilaize the parameters

    key[0] = 0;
    // loop
    for (int count = 0; count < V - 1; count++)
    {

        // check for the least value of weight connecting to the vertex and then include in th MST
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        // this is for including all the possible edges and later on selecting the right one using minkey
        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] != 0 && mstSet[v] == false && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // printing the MST: 
    cout << "Edge : Weight\n";
    for (int v = 1; v < V; v++)
    {
        cout << parent[v] << " - " << v << ": " << key[v] << "\n";
    }
}

int main()
{
    vector<vector<int>> graph;
    graph = {
        {0, 2, 3, 0, 0},
        {2, 0, 1, 4, 0},
        {3, 1, 0, 5, 6},
        {0, 4, 5, 0, 7},
        {0, 0, 6, 7, 0}};

    prims(graph);
}
