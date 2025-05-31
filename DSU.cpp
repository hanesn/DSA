#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    vector<int> size,parent;
    public:
    DisjointSet(int n){
        size.resize(n+1,1); // 1 based indexing
        parent.resize(n+1);
        for(int i=0;i<n+1;i++){
            parent[i]=i;
        }
    }
    int findparent(int node){
        if(node==parent[node]) return node;
        return parent[node]=findparent(parent[node]);
    }
    void unionbysize(int u,int v){
        int a=findparent(u);
        int b=findparent(v);
        if(a==b) return;
        if(size[a]<size[b]) swap(a,b);
        parent[b]=a;
        size[a]+=size[b];
    }
};
int main(){
    int nodes,edges;
    cin>>nodes>>edges;
    DisjointSet dsu=DisjointSet(nodes);
    while(edges--){
        int u,v;
        cin>>u>>v;
        dsu.unionbysize(u,v);
    }
    int connected_ct=0;
    for(int i=1;i<=nodes;i++){
        if(dsu.findparent(i)==i) connected_ct++;
    }
    cout<<connected_ct;
}