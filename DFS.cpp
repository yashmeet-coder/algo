#include <iostream>
#include <vector>
using namespace std;

class DFS
{
public:
    vector<vector<int>> adj_list;
    bool *visited;
    int n;

    DFS()
    {
        cout << "Enter the number of nodes: ";
        cin >> n;
        visited = new bool[n];
        for (int i = 0; i < n; i++)
        {
            visited[i] = false;
        }
    }

    void takeInput();
    void DFS_Traversal(int n1);
    void display();
};

void DFS::takeInput()
{
    vector<int> anodes;
    int node = 0;
    int a;
    int neighbors;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the number of neighbours of node " << node++ << " ";
        cin >> neighbors;
        cout << "Enter the nodes to which this node has an edge ";
        while (neighbors != 0)
        {
            cin >> a;
            anodes.push_back(a);
            neighbors--;
        }
        adj_list.push_back(anodes);
        anodes.clear();
    }
}

void DFS::display()
{
    for (int i = 0; i < adj_list.size(); i++)
    {
        cout << i << " - ";
        for (int j = 0; j < adj_list[i].size(); j++)
        {
            cout << adj_list[i][j] << " ";
        }
        cout << endl;
    }
}

void DFS::DFS_Traversal(int node)
{
    if (visited[node] == false)
    {
        visited[node] = true;
        cout << node << " ";
    }
    for (int i = 0; i < adj_list[node].size(); i++)
    {
        if (visited[adj_list[node][i]] == false)
        {
            DFS_Traversal(adj_list[node][i]);
        }
    }
}

int main()
{
    DFS obj;
    obj.takeInput();
    obj.display();
    int node;
    cout << "Enter the node at which to perform DFS: ";
    cin >> node;
    obj.DFS_Traversal(node);
}
