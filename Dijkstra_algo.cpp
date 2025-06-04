#include<bits/stdc++.h>
using namespace std;
vector<int> dijkstra(int n,vector<pair<int,int>> graph[],int src){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;// [wt,node]
    q.push({0,src});
    vector<int> dist(n,1e9);
    dist[src]=0;
    while(q.size()>0){
        int wt=q.top().first;
        int parentnode=q.top().second;
        q.pop();
        for(auto &child:graph[parentnode]){
            int edgewt=child.second;
            int childnode=child.first;
            if(dist[parentnode]+edgewt<dist[childnode]){
                dist[childnode]=dist[parentnode]+edgewt;
                q.push({dist[childnode],childnode});
            }
        }
    }
    return dist;
}
int main(){
    vector<pair<int,int>> graph[6];
    graph[0].push_back({1,4});
    graph[0].push_back({2,4});
    graph[1].push_back({0,4});
    graph[1].push_back({2,2});
    graph[2].push_back({0,4});
    graph[2].push_back({1,2});
    graph[2].push_back({3,3});
    graph[2].push_back({4,1});
    graph[2].push_back({5,6});
    graph[3].push_back({2,3});
    graph[3].push_back({5,2});
    graph[4].push_back({2,1});
    graph[4].push_back({5,3});
    graph[5].push_back({2,6});
    graph[5].push_back({3,2});
    graph[5].push_back({4,3});
    vector<int> ans=dijkstra(6,graph,0);
    for(auto &it:ans){
        cout<<it<<" ";
    }
}