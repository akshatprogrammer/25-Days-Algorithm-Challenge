#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin >> u >> v >> wt;
        adj[u].push_back(make_pair(v,wt));
        adj[v].push_back(make_pair(u,wt));
    }
    int source;
    cin >> source;

    // Dijkstra's Algo 
 //   priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
      priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
    vector<int> distTo(n+1,INT_MAX);
    distTo[source]=0;
    pq.push(make_pair(0,source));
    while(!pq.empty()){
        int node = pq.top().second;
        int dist = pq.top().first;
        pq.pop();

        vector<pair<int,int>> :: iterator it;
        for(it = adj[node].begin();it!=adj[node].end();it++){
            int next_node=it->first;
            int next_dist=it->second;

            if(distTo[next_node] > distTo[node]+next_dist){
                distTo[next_node] = distTo[node]+next_dist;
                pq.push(make_pair(distTo[next_node],next_node));
            }
        }
    }
    cout << "From source " <<  source << "  " << endl;
    for(int i=1;i<=n;i++){
        cout << i << " -> " << distTo[i] << endl;
    }
}