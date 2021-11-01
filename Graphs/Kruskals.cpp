#include<bits/stdc++.h>
using namespace std;
struct node{
    int u,v,wt;
    node(int first,int second,int weight){
        u=first;
        v=second;
        wt=weight;
    }
};
int findPar(int node,vector<int>&parent){
    if(node==parent[node]) return node;

    return findPar(parent[node],parent);
}
void unionn(int u,int v,vector<int>&parent,vector<int>&rank){
    u=findPar(u,parent);
    v=findPar(v,parent);

    if(rank[u]>rank[v]){
        parent[v]=u;
    }
    else if(rank[v]>rank[u]){
        parent[u]=v;
    }
    else{
        parent[v]=u;
        rank[u]++;
    }
}
int main(){
    int n,m;
    cin >> n >> m;
    vector<node> edges;
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin >> u >> v >> wt;
        edges.push_back(node(u,v,wt));
    }
    vector<int> parent(n+1);
    vector<int> rank(n+1,0);
    for(int i=1;i<=n;i++)
        parent[i]=i;
    
    vector<pair<int,int>> mst;
    int cost=0;
    for(auto it : edges){
        if(findPar(it.u,parent)!=findPar(it.v,parent)){
            cost+=it.wt;
            mst.push_back({it.u,it.v});

            unionn(it.u,it.v,parent,rank);
        }
    }
    cout << "MST COST -> " << cost << endl;

    for(auto it : mst){
        cout << it.first << " -> " << it.second << endl;
    }
}