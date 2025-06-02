// bfs version is kahn's algorithm
#include<bits/stdc++.h>
using namespace std;
vector<int> topologicalSort(int n,vector<int> graph[]){
    vector<int> indeg(n,0);
    for(int i=0;i<n;i++){
        for(auto &child:graph[i]){
            indeg[child]++;
        }
    }
    queue<int> q;
    for(int i=0;i<n;i++){
        if(indeg[i]==0){
            q.push(i);
        }
    }
    vector<int> topo;
    while(q.size()>0){
        int node=q.front();
        q.pop();
        topo.push_back(node);
        for(auto &child:graph[node]){
            indeg[child]--;
            if(indeg[child]==0){
                q.push(child);
            }
        }
    }
    return topo;
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