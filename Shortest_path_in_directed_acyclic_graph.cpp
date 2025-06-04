// using topological sort
// 1. do a topo sort on graph
// 2. take nodes out of stack and relax the edges
#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<bool> &visited,stack<int> &stk,vector<pair<int,int>> graph[]){
    visited[node]=1;
    for(auto &child:graph[node]){
        if(!visited[child.first]) dfs(child.first,visited,stk,graph);
    }
    stk.push(node);
}
stack<int> topologicalSort(int n,vector<pair<int,int>> graph[]){
    vector<bool> visited(n+1,0);
    stack<int> stk;
    for(int i=0;i<n;i++){
        if(!visited[i])
            dfs(i,visited,stk,graph);
    }
    return stk;
}
vector<int> shortestPath(vector<pair<int,int>> graph[],int n,int start){
    stack<int> stk=topologicalSort(n,graph);
    vector<int> dist(n,1e9);
    dist[start]=0;
    while(stk.size()>0){
        int node=stk.top();
        stk.pop();
        for(auto &child:graph[node]){
            int childnode=child.first;
            int wt=child.second;
            if(dist[node]+wt<dist[childnode]){
                dist[childnode]=dist[node]+wt;
            }
        }
    }
    return dist;
}
int main(){
    vector<pair<int,int>> graph[7];
    graph[0].push_back({1,2});  // {node,weight}
    graph[1].push_back({3,1});
    graph[2].push_back({3,3});
    graph[4].push_back({0,3});
    graph[4].push_back({2,1});
    graph[5].push_back({4,1});
    graph[6].push_back({4,2});
    graph[6].push_back({5,3});
    vector<int> ans=shortestPath(graph,7,6);
    for(auto &it:ans){
        cout<<it<<" ";
    }
}