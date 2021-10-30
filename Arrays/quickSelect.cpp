#include<bits/stdc++.h>
using namespace std;
int partition(int arr[],int pivot,int low,int high){
    int i=low,j=low;
    while(i<=high){
        if(arr[i]<=pivot){
            swap(arr[i],arr[j]);
            i++,j++;
        }
        else{
            i++;
        }
    }
    return (j-1);
}
int quickSelect(int arr[],int low,int high,int key){
    int pivot=arr[high];
    int pi = partition(arr,pivot,low,high);

    if(key > pi){
        return quickSelect(arr,pivot+1,high,key);
    }else if(key<pi){
        return quickSelect(arr,low,pi-1,key);
    }
    return arr[pi];
}
int main(){
    int arr[]={4,3,1,2,6,7,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k=3;
    cout << quickSelect(arr,0,n-1,k) << endl;
    return 0;
}