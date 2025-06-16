// definition - nodes on whose removal from the graph
// breaks into multiple components

// 1. time[] -> dfs time inserts on
// 2. lowestTime[] -> lowest time insertion of all adjacent nodes except parent and visited nodes
#include <bits/stdc++.h>
using namespace std;
vector<int> t,lowt;
int timer=0;
void dfs(int node,int parent,vector<bool> &visited,vector<int> &mark,vector<int> graph[]){
    visited[node]=1;
    t[node]=timer;
    lowt[node]=timer;
    timer++;
    int child=0;
    for(auto &child:graph[node]){
        if(child==parent) continue;
        if(!visited[child]){
            dfs(child,node,visited,mark,graph);
            lowt[node]=min(lowt[node],lowt[child]);
            if(lowt[child]>=t[node] && parent!=-1){
                mark[node]=1;
            }
        }else{
            lowt[node]=min(lowt[node],t[child]);
        }
    }
    if(child>1 && parent==-1){
        mark[node]=1;
    }
}
vector<int> articulationPoints(int n,vector<int> graph[]){
    vector<bool> visited(n,0);
    t.resize(n);
    lowt.resize(n);
    vector<int> mark(n,0);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i,-1,visited,mark,graph);
        }
    }

    vector<int> ans;
    for(int i=0;i<n;i++){
        if(mark[i]){
            ans.push_back(i);
        }
    }
    return ans;
}
int main(){
    vector<vector<int>> edges;
    edges.push_back({0,1});
    edges.push_back({0,2});
    edges.push_back({0,3});
    edges.push_back({2,4});
    edges.push_back({2,5});
    edges.push_back({4,6});
    edges.push_back({5,6});
    edges.push_back({2,3});
    vector<int> graph[7];
    for(auto &it:edges){
        graph[it[0]].push_back(it[1]);
        graph[it[1]].push_back(it[0]);
    }
    vector<int> ans=articulationPoints(7,graph);
    for(auto &it:ans){
        cout<<it<<" ";
    }
}