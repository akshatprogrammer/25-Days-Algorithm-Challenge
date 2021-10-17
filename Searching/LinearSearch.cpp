#include<bits/stdc++.h>
using namespace std;
bool linearSearch(int arr[],int n,int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key)
            return true;
    }
    return false;
}
int main(){
    int arr[]={1,4,5,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key=7;
    if(linearSearch(arr,n,key)){
        cout << "Present" << endl;
    }
    else{
        cout << "Not Present" << endl;
    }
    return 0;
}