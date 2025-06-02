#include<bits/stdc++.h>
using namespace std;
bool dfs(int node,vector<bool> &visited,vector<bool> &pathvisited,vector<int> graph[]){
    visited[node]=1;
    pathvisited[node]=1;
    for(auto &child:graph[node]){
        if(!visited[child]){
            if(dfs(child,visited,pathvisited,graph)) return true;
        }else if(pathvisited[child]){
            return true;
        }
    }

    pathvisited[node]=0;
    return false;
}
bool isCyclic(int V, vector<vector<int>> &edges) {
    vector<int> graph[V+1];
    for(auto &edge:edges){
        graph[edge[0]].push_back(edge[1]);
    }
    vector<bool> visited(V+1,0);
    vector<bool> pathvisited(V+1,0);
    for(int i=1;i<=V;i++){
        if(!visited[i]){
            if(dfs(i,visited,pathvisited,graph)) return true;
        }
    }
    return false;
}
int main(){
    int n;
    n=10;
    vector<vector<int>> edges;
    edges.push_back({1,2});
    edges.push_back({8,2});
    edges.push_back({8,9});
    edges.push_back({9,10});
    edges.push_back({10,8});
    edges.push_back({2,3});
    edges.push_back({3,7});
    edges.push_back({3,4});
    edges.push_back({4,5});
    edges.push_back({7,5});
    edges.push_back({5,6});
    cout<<isCyclic(n,edges);
}