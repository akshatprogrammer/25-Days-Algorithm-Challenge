#include<bits/stdc++.h>
using namespace std;
bool binarySearch(int arr[],int n,int key){
    int low=0,high=n-1;
    while(low<=high){
        int mid=high-(high-low)/2;
        if(arr[mid]==key)
            return true;
        else if(arr[mid]>key){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return false;
}
int main(){
    int arr[]={1,2,3,4,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int key=9;
    if(binarySearch(arr,n,key))
        cout << "Present!"<< endl;
    else
        cout << "Not Present!" << endl;
    return 0;
}