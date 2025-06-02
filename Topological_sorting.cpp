// topological sort is only possible for directed acyclic graph
#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<bool> &visited,stack<int> &stk,vector<int> graph[]){
    visited[node]=1;
    for(auto &child:graph[node]){
        if(!visited[child]) dfs(child,visited,stk,graph);
    }
    stk.push(node);
}
vector<int> topologicalSort(int n,vector<int> graph[]){
    vector<bool> visited(n+1,0);
    stack<int> stk;
    for(int i=0;i<n;i++){
        if(!visited[i])
            dfs(i,visited,stk,graph);
    }
    vector<int> ans;
    while(stk.size()>0){
        ans.push_back(stk.top());
        stk.pop();
    }
    return ans;
}
int main(){
    int n=6;
    vector<int> graph[n+1];
    graph[5].push_back(0);
    graph[5].push_back(2);
    graph[2].push_back(3);
    graph[3].push_back(1);
    graph[4].push_back(0);
    graph[4].push_back(1);
    vector<int> ans=topologicalSort(n,graph);
    for(auto &it:ans){
        cout<<it<<" ";
    }
}