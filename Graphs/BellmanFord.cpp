#include<bits/stdc++.h>
using namespace std;
struct node{
    int u,v,wt;
    node(int f,int s,int w){
        u=f;
        v=s;
        wt=w;
    }
};
int main(){
    int n,m;
    cin >> n >> m;
    vector<node> edges;
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin >> u >> v >> wt;
        edges.push_back(node(u,v,wt));
    }
    int src;
    cin >> src;

    vector<int> distTo(n,10000000);
    distTo[src]=0;

    for(int i=1;i<=n-1;i++){
        for(auto it : edges){
            if(distTo[it.u]+it.wt < distTo[it.v]){
                distTo[it.v]=distTo[it.u]+it.wt;
            }
        }
    } 
    // To detect Negative Cycle
    int flag=0;
    for(auto it : edges){
        if(distTo[it.u]+it.wt < distTo[it.v]){
                cout << "Negative Cycle " << endl;
                flag=1;
                break;
            }
    }
    if(!flag){
        for(int i=0;i<n;i++){
            cout <<"from" <<  i << " -> " << distTo[i] << endl;
        }
    }  

}