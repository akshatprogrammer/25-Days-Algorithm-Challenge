#include<bits/stdc++.h>
using namespace std;
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partition1(int arr[],int l,int r){
    int pivot=arr[r];
    int i=l-1;
    for(int j=l;j<=r-1;j++){
        if(arr[j]<pivot)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[r]);
    return (i+1);

}

void quickSort(int arr[],int l,int r){
    if(l<r)
    {int p=partition1(arr,l,r);
    quickSort(arr,l,p-1);
    quickSort(arr,p+1,r);}
}
int main(){
    int arr[]={3,9,4,1,11,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    quickSort(arr,0,n-1);
    for(int i=0;i<n;i++)
        cout << arr[i] << " ";
        cout << endl;
    return 0;
}