#include <iostream>
#include <cstdlib>
#include <ctime>
#include <time.h>
using namespace std;
class quickSort{
    public:
    int *arr;
    int len;
    int com;
    quickSort(int n){
        len=n;
        arr=new int[len];
        com=0;
    }
    void input(){
        for(int i=0;i<len;i++)
        arr[i]=rand()%100;
    }
    void display(){
        cout<<len;
        cout<<"\t\t"<<com<<endl;
    }
    int partition(int *arr,int p, int r){
        int x=arr[r];
        int i=p-1;
        for(int j=p;j<r;j++){
            com++;
            if (arr[j]<=x){
                i++;
                swap(arr[i],arr[j]);
            }
        }
        swap(arr[i+1],arr[r]);
        return (i+1);
    }
    void quick_sort(int *arr, int p, int r)
    {
        if(p<r){
            int q=partition(arr,p,r);
            quick_sort(arr,p,q-1);
            quick_sort(arr,q+1,r);
        }
    }
};
int main(){
    srand(time(0));
    for(int i=0;i<100;i++){
    quickSort obj(30+rand()%(1000-30+1));
    obj.input();
    // obj.display();
    obj.quick_sort(obj.arr,0,9);
    obj.display();
    }
    return 0;
}