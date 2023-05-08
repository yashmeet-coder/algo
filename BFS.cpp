#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class BFS
{
public:
    vector<vector<int>> alist;
    bool *visited;
    int n;

    BFS()
    {
        cout << "Enter the number of nodes: ";
        cin >> n;
        visited = new bool[n];
        for (int i = 0; i < n; i++)
        {
            visited[i] = false;
        }
    }

    void input();
    void BFS_Tree();
    void display();
};

void BFS::input()
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
        alist.push_back(anodes);
        anodes.clear();
    }
}

void BFS::display()
{
    for (int i = 0; i < alist.size(); i++)
    {
        cout << i << " - ";
        for (int j = 0; j < alist[i].size(); j++)
        {
            cout << alist[i][j] << " ";
        }
        cout << endl;
    }
}

void BFS::BFS_Tree()
{
    queue<int> q1;
    int node;
    cout << "Enter the node from which you want to start BFS traversal: ";
    cin >> node;
    q1.push(node);
    visited[node] = true;
    while (!q1.empty())
    {
        int temp = q1.front();
        q1.pop();
        cout << temp << " ";
        for (int i = 0; i < alist[temp].size(); i++)
        {
            if (visited[alist[temp][i]] == false)
            {
                q1.push(alist[temp][i]);
                visited[alist[temp][i]] = true;
            }
        }
    }
}

int main()
{
    BFS obj;
    obj.input();
    obj.display();
    obj.BFS_Tree();
}
