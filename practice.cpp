#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct Edge
{
    int u, v, w;
    bool operator<(Edge const &other)
    {
        return w < other.w; 
    }
};

void unionSet(int a, int b, vector<int> &parent, vector<int> &rank)
{
    a = findParent(a, parent);
    b = findParent(b, parent);

    if (a != b)
    {
        if (rank[a] < rank[b])
        {
            swap(a, b);
        }
        parent[b] = a;

        if (rank[a] == rank[b])
        {
            rank[a]++;
        }
    }
}

int findParent(int u, vector<int> &parent)
{
    if (parent[u] == u)
    {
        return u;
    }
    return parent[u] = findParent(parent[u], parent);
}

void kruskal(vector<Edge> &edges, int n)
{
    sort(edges.begin(), edges.end());

    vector<int> parent(n), rank(n, 0);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    int totalCost = 0;
    vector<Edges> mst;
    for (auto &e : edges)
    {
        if (findParent(e.u, parent) != findParent(e.v, parent))
        {
            totalCost += e.w;
            mst.push_back(e);
            unionSet(e.u, e.v, parent, rank);
        }
    }

    cout << "Edges in MST: " << endl;
    for (auto &e : mst)
    {
        cout << e.u << "-" << e.v << ": " << e.w << endl;
    }
}

int main()
{
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}};

    int n = 4;
}