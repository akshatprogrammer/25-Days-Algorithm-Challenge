#include<bits/stdc++.h>
using namespace std;
void selectionSort(int arr[],int n){
    int i,j,min_ele;
    for(i=0;i<n-1;i++){
        min_ele=i;
        for(j=i+1;j<n;j++){
            if(arr[j]<arr[min_ele]){
                min_ele=j;
            }
        }
        swap(arr[min_ele],arr[i]);
    }
}
int main(){
    int arr[]={64,25,12,22,11};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr,n);
    for(int i=0;i<n;i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}