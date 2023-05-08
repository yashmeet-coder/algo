#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<vector<int>> v1;
    int nodes;
    int weight;
    int profit;
    cout<<"Enter the total number of nodes: ";
    cin>>nodes;
    for(int i=0;i<nodes;i++){
        cout<<"Enter the weight of "<<i<<"th node: ";
        cin>>weight;
        cout<<"Enter the profit of "<<i<<"th node: ";
        cin>>profit;
        v1.push_back({weight,profit});
    }

    for(int i=0;i<nodes;i++){
        for(int j=0;j<2;j++){
            cout<<v1[i][j]<<" ";
        }
        cout<<endl;
    }

}