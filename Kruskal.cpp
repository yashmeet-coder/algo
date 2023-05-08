#include <iostream>
#include <algorithm>
using namespace std;

// to maintain and union disjoint sets
// for connected components
class UnionFind
{
    int n;
    int *parent; // disjoint sets

public:
    UnionFind(int n)
    {
        this->n = n;
        parent = new int[n];

        // initially all are separate disjoint sets of single elements
        // parent[i] = i means set/component name
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int u)
    {
        if (u == parent[u])
            return u;
        return find(parent[u]);
    }

    void union_sets(int a, int b)
    {
        int set_a = find(a);
        int set_b = find(b);

        // parent of set_a to set_b
        parent[set_a] = set_b;
    }
};

// edge construct - undirected
class Edge
{
public:
    int u, v, wt;
};

bool edge_comparator(Edge x, Edge y)
{
    return x.wt < y.wt;
}

// based on edge list
class Graph
{
    int n, e;
    Edge *edge_list;

public:
    Graph(int n, int e)
    {
        this->n = n;
        this->e = e;
        edge_list = new Edge[e];
    }

    ~Graph()
    {
        delete edge_list;
    }

    void input_weights()
    {
        cout << "Enter the edges and their weight (u, v, w)" << endl;
        for (int i = 0; i < e; i++)
            cin >> edge_list[i].u >> edge_list[i].v >> edge_list[i].wt;
    }

    void display()
    {
        for (int i = 0; i < e; i++)
            cout << edge_list[i].u << " " << edge_list[i].v << " " << edge_list[i].wt << endl;
    }

    void kruskals()
    {
        // 1. Sorting edges by weights in increasing order
        sort(edge_list, edge_list + e, edge_comparator);

        // 2. Union find for vertices
        UnionFind component = UnionFind(n);

        bool mst[e]; // for mst edges
        for (int i = 0; i < e; i++)
            mst[i] = false;

        // 3. Processing edges and including in mst

        int x, y;
        for (int edge = 0; edge < e; edge++)
        {
            x = edge_list[edge].u;
            y = edge_list[edge].v;

            if (component.find(x) != component.find(y))
            { // they are disjoint
                // include them to mst
                mst[edge] = true;
                component.union_sets(x, y); // union their sets or merge components
            }
        }

        // print mst and cost
        int cost = 0;
        cout << "\nMST Edges nodeA -> nodeB" << endl;
        for (int edge = 0; edge < e; edge++)
        {
            if (mst[edge])
            {
                cout << edge_list[edge].u << " -> " << edge_list[edge].v << endl;
                cost += edge_list[edge].wt;
            }
        }
        cout << "COST to build it : " << cost;
    }
};

int main()
{
    int n, e;
    cout << "Enter #vertices and #edges : ";
    cin >> n >> e;
    Graph g(n, e);
    g.input_weights();
    g.kruskals();
    return 0;
}