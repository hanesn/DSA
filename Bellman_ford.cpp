// helps to detect negative cycles as well
// only applicable in directed graph

// relax all the edges n-1 times where n=nodes
// problem: return dist array or {-1} is negative cycle exists
#include<bits/stdc++.h>
using namespace std;
vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
	vector<int> dist(V, INT_MAX);
	dist[src] = 0;
  
	// Relaxation of all the edges V times, not (V - 1) as we
    // need one additional relaxation to detect negative cycle
	for (int i = 0; i < V; i++) {
	    
		for (vector<int> edge : edges) {
			int u = edge[0];
			int v = edge[1];
			int wt = edge[2];
			if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
			    
                // If this is the Vth relaxation, then there is
                // a negative cycle
                if(i == V - 1)
                    return {-1};
               
                dist[v] = dist[u] + wt;
            }
		}
	}
    return dist;
}
int main(){
    int V=5;
     vector<vector<int>> edges = {
        {1, 3, 2}, 
        {4, 3, -1},
        {2, 4, 1}, 
        {1, 2, 1},
        {0, 1, 5} 
    };
    int src=0;
    vector<int> ans = bellmanFord(V, edges, src);
    for (int dist : ans) 
        cout << dist << " ";
}