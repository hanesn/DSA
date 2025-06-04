// all weights are 1
#include<bits/stdc++.h>
using namespace std;
vector<int> shortestPath(int n,vector<int> graph[],int src){
    vector<int> dist(n,1e9);
    dist[src]=0;
    queue<int> q;
    q.push(src);
    while(q.size()>0){
        int node=q.front();
        q.pop();
        for(auto &child:graph[node]){
            if(dist[child]>dist[node]+1){
                dist[child]=1+dist[node];
                q.push(child);
            }
        }
    }
    return dist;
}
int main(){
    vector<int> graph[9];
    graph[0].push_back(1);
    graph[0].push_back(3);
    graph[1].push_back(0);
    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[2].push_back(1);
    graph[2].push_back(6);
    graph[3].push_back(0);
    graph[3].push_back(4);
    graph[4].push_back(3);
    graph[4].push_back(5);
    graph[5].push_back(4);
    graph[5].push_back(6);
    graph[6].push_back(2);
    graph[6].push_back(5);
    graph[6].push_back(7);
    graph[6].push_back(8);
    graph[7].push_back(6);
    graph[7].push_back(8);
    graph[8].push_back(6);
    graph[8].push_back(7);
    vector<int> ans=shortestPath(9,graph,0);
    for(auto &it:ans){
        cout<<it<<" ";
    }
}