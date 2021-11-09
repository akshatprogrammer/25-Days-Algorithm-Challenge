#include<bits/stdc++.h>
using namespace std;

// sqaure sorted

int main(){
    int arr[]={-4,-3,1,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);

    int left=0,right=n-1;
    int out[n];
    //i=0;
    for(int i=n-1;i>=0;i--){
        if(abs(arr[left])>arr[right]){
            out[i]=arr[left]*arr[left];
            left++;
        }else{
            out[i]=arr[right]*arr[right];
            right--;
        }
    }
    for(int i=0;i<n;i++)
        cout << out[i] << " ";
    return 0;
}

