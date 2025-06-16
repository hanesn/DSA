// kosaraju's algo
// only valid for directed graphs
// definition of strongly connected components - every pair of vertex
// is rechable by every other vertex

// steps:
// 1. sort all the edges according to finishing time
// 2. reverse the graph
// 3. do dfs
#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<bool> &visited,vector<int> graph[],stack<int> &stk){
    visited[node]=1;
    for(auto &child:graph[node]){
        if(!visited[child]){
            dfs(child,visited,graph,stk);
        }
    }
    stk.push(node);
}
void dfs2(int node,vector<bool> &visited,vector<int> reversed_graph[]){
    visited[node]=1;
    for(auto &child:reversed_graph[node]){
        if(!visited[child]){
            dfs2(child,visited,reversed_graph);
        }
    }
}
int kosaraju(int n,vector<int> graph[]){
    vector<bool> visited(n,0);
    stack<int> stk;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i,visited,graph,stk);
        }
    }

    vector<int> reversed_graph[n];
    for(int i=0;i<n;i++){
        visited[i]=0;
        for(auto &child:graph[i]){
            reversed_graph[child].push_back(i);
        }
    }

    int scc=0;
    while(stk.size()>0){
        int node=stk.top();
        stk.pop();
        if(!visited[node]){
            scc++;
            dfs2(node,visited,reversed_graph);
        }
    }
    return scc;
}
int main(){
    vector<int> graph[8];
    graph[0].push_back(1);
    graph[1].push_back(2);
    graph[2].push_back(0);
    graph[2].push_back(3);
    graph[3].push_back(4);
    graph[4].push_back(5);
    graph[4].push_back(7);
    graph[5].push_back(6);
    graph[6].push_back(4);
    graph[6].push_back(7);
    cout<<kosaraju(8,graph);
}