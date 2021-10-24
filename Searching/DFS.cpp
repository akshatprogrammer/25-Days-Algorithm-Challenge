#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int> adj[],vector<int> &vis,int node,vector<int> &ans){
    ans.push_back(node);
    vis[node]=1;

    for(auto it : adj[node]){
        if(!vis[it])
            dfs(adj,vis,it,ans);
    }
}
vector<int> dfs(vector<int> adj[],int n){
    vector<int> vis(n,0);
    vector<int> ans;
    for(int i=1;i<n;i++){
        if(vis[i]==0)
            dfs(adj,vis,i,ans);
    }
    return ans;
}
int main(){
    int n,m;
    cin >> n >> m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> res = dfs(adj,n);
    for(int i=0;i<res.size();i++)
        cout << res[i] << " ";
        cout << endl;
    return 0;
}