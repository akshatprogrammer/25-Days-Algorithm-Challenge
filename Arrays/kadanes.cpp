#include<bits/stdc++.h>
using namespace std;
int kadanes(int arr[],int n){
    int max=INT_MIN,ans_max=0;
    for(int i=0;i<n;i++){
        ans_max+=arr[i];
        if(ans_max>max){
            max=ans_max;
        }
        if(ans_max<0){
            ans_max=0;
        }
    }
    return max;
}
int main(){
    int arr[]={-2,-3,4,-1,-2,1,5,-3};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << kadanes(arr,n);
    cout << endl;
    return 0;
}