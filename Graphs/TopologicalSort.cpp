#include<bits/stdc++.h>
using namespace std;
void topoSortDFS(int node,vector<int> adj[],vector<int>&vis,stack<int>&s){
    vis[node]=1;
    for(auto it : adj[node]){
        if(!vis[it]){
            topoSortDFS(it,adj,vis,s);
            // calling recursive dfs 
        }
    }
    s.push(node);
}
vector<int> topoSort(vector<int> adj[],int n){
    vector<int> visited(n,0);
    stack<int> s;
    vector<int> res;
    for(int i=0;i<n;i++){
        if(visited[i]==0){
            topoSortDFS(i,adj,visited,s);
        }
    }
    while(!s.empty()){
        res.push_back(s.top());
        s.pop();
    }
    return res;
}
int main(){
    int n,m;
    cin >> n >> m;
    vector<int> adj[n];
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<int> ans = topoSort(adj,n);
    for(int i=0;i<ans.size();i++)
        cout << ans[i] << " ";
    return 0;
}