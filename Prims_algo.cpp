#include<bits/stdc++.h>
using namespace std;
int spanningTree(int n,vector<pair<int,int>> graph[]){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;   // [wt,node]
    vector<bool> visited(n,0);
    q.push({0,0});
    int sum=0;
    while(q.size()>0){
        auto it=q.top();
        q.pop();
        int node=it.second;
        int wt=it.first;
        if(visited[node]) continue;
        visited[node]=1;
        sum+=wt;
        for(auto &child:graph[node]){
            int childnode=child.first;
            int edgewt=child.second;
            if(!visited[childnode]){
                q.push({edgewt,childnode});
            }
        }
    }
    return sum;
}
int main(){
    vector<pair<int,int>> graph[6];
    graph[0].push_back({2,1});
    graph[2].push_back({0,1});
    graph[0].push_back({1,2});
    graph[1].push_back({0,2});
    graph[2].push_back({1,1});
    graph[1].push_back({2,1});
    graph[2].push_back({4,2});
    graph[4].push_back({2,2});
    graph[4].push_back({3,1});
    graph[3].push_back({4,1});
    graph[2].push_back({3,2});
    graph[3].push_back({2,2});
    cout<<spanningTree(6,graph);
}