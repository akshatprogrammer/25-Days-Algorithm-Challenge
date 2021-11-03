#include<bits/stdc++.h>
using namespace std;
int parent[10];
for(int i=0;i<n;i++){
    parent[i]=i;
}
void unionn(int x,int y){
    find(parent[y])=find(x);
}
int find(int x){
    if(x!=parent[x]){
        return find(parent[x]);
    }
    return x;
}