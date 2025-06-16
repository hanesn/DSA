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
bool static cmp(vector<int> &v1,vector<int> &v2){
    return v1[2]<v2[2];
}
int kruskalsMST(int n, vector<vector<int>> &edges) {
    sort(edges.begin(),edges.end(),cmp);
    DisjointSet dsu(n);
    int sum=0;
    for(auto &it:edges){
        if(dsu.findparent(it[0])!=dsu.findparent(it[1])){
            dsu.unionbysize(it[0],it[1]);
            sum+=it[2];
        }
    }
    return sum;
}
int main(){
    vector<vector<int>> edges = {
        {5,4,9},{5,1,4},{4,1,1},{4,3,5},{1,2,2},{4,2,3},{3,2,3},{3,6,8},{2,6,7}
    };
    cout<<kruskalsMST(6, edges);
}