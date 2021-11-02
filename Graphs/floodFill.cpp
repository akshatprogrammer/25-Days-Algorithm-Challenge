#include<bits/stdc++.h>
using namespace std;
void dfs(int i,int j,int n, int m,vector<vector<int>>&image,vector<vector<int>> &vis,int newC,int old){
        
        if(i<0 or j<0 or i>=n or j>=m) return;
        
        if(vis[i][j] or image[i][j]!=old) return;
        
        vis[i][j]=1;
        image[i][j]=newC;
        dfs(i+1,j,n,m,image,vis,newC,old);
        dfs(i-1,j,n,m,image,vis,newC,old);
        dfs(i,j+1,n,m,image,vis,newC,old);
        dfs(i,j-1,n,m,image,vis,newC,old);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int x = image.size();
        int y = image[0].size();
        
        int oldColor=image[sr][sc];
        
        vector<vector<int>> vis(x,vector<int> (y,0));
        
        dfs(sr,sc,x,y,image,vis,newColor,oldColor);
        
        return image;
    }
int main(){
    int n,m;
    cin >>n>>m;
    vector<vector<int>> image(n,vector<int>(m,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> image[i][j];
        }
    }
    int x,y;
    cin >> x >>y;
    int newColor;
    cin >> newColor;

    floodFill(image,x,y,newColor);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << image[i][j] << " ";
        }cout << endl;
    }
}