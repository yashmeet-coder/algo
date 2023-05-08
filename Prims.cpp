#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class Heap{
public:
    vector<int> map_node_index; //node is at what index
    Heap(int nodes); //number of nodes
    void build_heap(vector<vector<int>> &node_key); //takes an array and converts it to heap
    vector<int> delete_min(vector<vector<int>> &heap); //to extract the minimum from the heap
    void heapify(vector<vector<int>> &heap, int current); //maintain heap property
    int change_key(vector<vector<int>> &heap, int node, int new_key); //to update key value
    void print(vector<vector<int>> &heap); //helps in debugging
};

Heap::Heap(int nodes){
    for (int i=0; i<nodes; i++)
    {map_node_index.push_back(i);} //map such that ith node has map_node_index[i] index in the heap
}

void Heap::heapify(vector<vector<int>> &heap, int current){
    int minimum=current; 
    int lchild=2*current+1; //left child
    int rchild=2*current+2; //right child
    if (lchild<heap.size() && heap[lchild][1]<heap[minimum][1]) 
    {minimum=lchild;} //if lchild exists then check and update mininmum
    if (rchild<heap.size() && heap[rchild][1]<heap[minimum][1])
    {minimum=rchild;} //similar to left case
    if (minimum!=current) //if true then heap property is violated and should be established
    {
        int current_node=heap[current][0]; //node value of element at current index
        int minimum_node=heap[minimum][0]; //node value of element at minimum index
        swap(heap[minimum], heap[current]); //swap nodes to establish heap property
        swap(map_node_index[current_node], map_node_index[minimum_node]); //update the map
        heapify(heap, minimum); //recursive call
    }
}

void Heap::build_heap(vector<vector<int>> &node_key){
    int current=node_key.size()/2-1; //first non leaf node from the end
    while (current>=0)
    {
        heapify(node_key, current); //establish heap property
        current--;
    }
}

vector<int> Heap::delete_min(vector<vector<int>> &heap){
    vector<int> min_node_key=heap.front(); //will be returned at the end
    int min_node=heap[0][0]; //node value of the next node
    int back_node=(heap.back())[0]; //node value of the last node in the heap
    swap(heap.front(), heap.back()); //swap first value with last value
    swap(map_node_index[min_node],  map_node_index[back_node]); //update the map
    heap.pop_back(); //remove the last element as it is to be extracted
    heapify(heap, 0); //establish heap property from the root
    return min_node_key;
}

int Heap::change_key(vector<vector<int>> &heap, int node, int new_key){
    int index=map_node_index[node]; //calculate the index of the node whose key is to be updated
    if (heap[index][1]<=new_key) //no need to do any change
    {return 0;}
    heap[index][1]=new_key; //assign the new value
    int parent=(index-1)/2;
    while (parent>=0 && heap[parent][1]>heap[index][1]) //propogates upwards untill heap property is established
    {
        int parent_node=heap[parent][0]; //value of node of parent
        swap(heap[index], heap[parent]); //swap nodes to establish heap property
        swap(map_node_index[node], map_node_index[parent_node]); //update the map
        index=parent;
        parent=(index-1)/2;
    }
    return 1;
}

void Heap::print(vector<vector<int>> &heap){
    cout << "Heap" << endl;
    for (int i=0; i<heap.size(); i++)
    {cout << "\t(" << heap[i][0] << ", " << heap[i][1] << ")" << endl;}
    cout << endl;
    cout << "Node, index" << endl;
    for (int i=0; i<map_node_index.size(); i++)
    {cout << i << ", " << map_node_index[i] << endl;}
    cout << endl;
}

class Prims{
public:
    vector<int> visited; //to keep track of visited nodes
    vector<vector<int>> mst(const vector<vector<vector<int>>> alist); //returns a vector of edges
    //alist is such that at each index we have a list, in that list each element is a tuple (a, b) where a is the neighbour and b is the distance between them
};

vector<vector<int>> Prims::mst(const vector<vector<vector<int>>> alist){
    vector<vector<int>> tree; //will be returned
    vector<int> parent; //will hold the end point information of each edge to be added to tree
    vector<vector<int>> heap_array; //array to be used as the heap
    for (int i=0; i<alist.size(); i++)
    {
        visited.push_back(false); //no node is vivited
        parent.push_back(i); // parent 
        heap_array.push_back({i, 1000}); //set the key value of every node high
    }
    heap_array[0][1]=0; //key of the zero th node will be made 0 so that it is selected first to form the partial tree
    Heap heap(alist.size());
    heap.build_heap(heap_array);
    
    while (!heap_array.empty())
    {
        vector<int> current_node_key=heap.delete_min(heap_array); //extract the node_key to be added to the tree
        tree.push_back({parent[current_node_key[0]], current_node_key[0], current_node_key[1] }); //extract the parent of the current node and add to the tree
        //the edge of (0,0) will be added since 0th node will be selected in the first iteration, and it is set to be its own parent. This edge will have to be deleted as it does not belong to the mst.
        visited[current_node_key[0]]=true; //mark the current node to be true
        if (current_node_key[0]==0)
        {tree.pop_back();}
        for (int i=0; i<alist[current_node_key[0]].size(); i++) //for all neighbours of current node
        {
            int neighbour=alist[current_node_key[0]][i][0]; //extraxt the neighbour node
            if (!visited[neighbour])
            {
                int change=heap.change_key(heap_array, neighbour, alist[current_node_key[0]][i][1]);
                if (change)
                {parent[neighbour]=current_node_key[0];}
            }
        }
    }
    return tree;
}

int main(){
    vector<vector<vector<int>>> alist;
    int nodes;
    cout << "Enter the number of nodes in the graph : ";
    cin >> nodes;
    for (int i=0; i<nodes; i++)
    {
        int neighbours;
        cout << "Enter the number of neighbours of node " << i << " : ";
        cin >> neighbours;
        cout << "Enter the neighbours along with their distance from node " << i << " : " << endl;
        
        vector<vector<int>> anodes;
        for (int j=0; j<neighbours; j++)
        {
            int n, d;
            cin >> n;
            cin >> d;
            anodes.push_back({n, d});
        }
        alist.push_back(anodes);
        cout << endl;
    }
    Prims prims;
    vector<vector<int>> tree=prims.mst(alist);
    cout << "Edges included in the Minimum Spanning Tree are : " << endl;
    int sum=0;
    for (int i=0; i<tree.size(); i++)
    {
        cout << "( "<< tree[i][0] << ", " << tree[i][1] << " ) " 
             << "edge cost : " << tree[i][2] << endl;
        sum+=tree[i][2];
    }
    cout << endl << "Minimum Cost : " << sum << endl; 
    return 0;
}