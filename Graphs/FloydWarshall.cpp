#include<bits/stdc++.h>
using namespace std;
#define V 4
#define INF 99999
int main(){
     int graph[V][V] = { { 0, 5, INF, 10 },
                        { INF, 0, 3, INF },
                        { INF, INF, 0, 1 },
                        { INF, INF, INF, 0 } };



    int dp[V][V];
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            dp[i][j] = graph[i][j];


    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if (dp[i][j] > (dp[i][k] + dp[k][j])
                    && (dp[k][j] != INF
                        && dp[i][k] != INF)){
                    dp[i][j] = dp[i][k]+dp[k][j];
                }
            }
        }
    }   

    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(dp[i][j]==INF){
                cout << "INF ";
            }else{
                cout << dp[i][j] << " ";
            }
        }cout << endl;
    }                        
}