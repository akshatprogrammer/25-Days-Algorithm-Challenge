#include<iostream>
using namespace std;
void insertionSort(int arr[],int n){
    int temp,prev;
    for(int i=1;i<n;i++){
        temp=arr[i];
        prev=i-1;
        while(prev>=0 and arr[prev]>temp){
            arr[prev+1]=arr[prev];
            prev--;
        }
    arr[prev+1]=temp;
    }
}
int main(){
    int arr[]={1,4,5,6,7,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr,n);
    for(int i=0;i<n;i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}  