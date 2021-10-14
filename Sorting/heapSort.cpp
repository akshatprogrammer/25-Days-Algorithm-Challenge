#include<bits/stdc++.h>
using namespace std;
void heapify(int arr[],int n,int i){
    int c1=2*i+1;
    int c2=2*i+2;
    int max=i;
    if(c1<n and arr[c1]>arr[max])
        max=c1;
    
    if(c2<n and arr[c2]>arr[max])
        max=c2;
    
    if(max!=i){
        swap(arr[i],arr[max]);
        heapify(arr,n,max);
    }
}
void heapsort(int arr[],int n){
    // build heap
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }
    // one by one extract an element from heap
    for(int i=n-1;i>0;i--){
        // move current root to end
        swap(arr[0],arr[i]);

        // call max heapify to reduced heap
        heapify(arr,i,0);
    }
}
int main(){
    int arr[]={4,10,3,5,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    heapsort(arr,n);
    for(int i=0;i<n;i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}