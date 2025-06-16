// 1. time[] -> dfs time inserts on
// 2. lowestTime[] -> lowest time insertion of all adjacent nodes except parent
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;
vector<int> t,lowt;
int timer=0;
void dfs(int node,int parent,vector<bool> &visited,vector<int> graph[]){
    visited[node]=1;
    t[node]=timer;
    lowt[node]=timer;
    timer++;
    for(auto &child:graph[node]){
        if(child==parent) continue;
        if(!visited[child]){
            dfs(child,node,visited,graph);
            lowt[node]=min(lowt[node],lowt[child]);
            if(lowt[child]>lowt[node]){
                ans.push_back({child,node});
            }
        }else{
            lowt[node]=min(lowt[node],lowt[child]);
        }
    }
}
vector<vector<int>> getBridges(int n, vector<vector<int>>& connections) {
    vector<int> graph[n];
    for(auto &it:connections){
        graph[it[0]].push_back(it[1]);
        graph[it[1]].push_back(it[0]);
    }
    vector<bool> visited(n,0);
    
    dfs(0,-1,visited,graph);
    return ans;
}
int main(){
    vector<vector<int>> edges={{0,1},{1,2},{2,0},{1,3}};
    vector<vector<int>> ans1=getBridges(4,edges);
    for(auto &it:ans1){
        cout<<it[0]<<" "<<it[1]<<'\n';
    }
}