// You are given two arrays: deadline[], and profit[], which represent a set of jobs, 
// where each job is associated with a deadline, and a profit. 
// Each job takes 1 unit of time to complete, and only one job can be scheduled at a time. 
// You will earn the profit associated with a job only if it is completed by its deadline.

// Your task is to find:
// The maximum number of jobs that can be completed within their deadlines.
// The total maximum profit earned by completing those jobs.
// https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

// algo;
// 1. sort jobs in increasing order
// 2. maintain a min heap to store selected jobs and replace lower profit jobs when 
//      more profitable jobs comes
#include<bits/stdc++.h>
using namespace std;
vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
    vector<pair<int,int>> v;
    int n=profit.size();
    for(int i=0;i<n;i++){
        v.push_back({deadline[i],profit[i]});
    }
    sort(v.begin(),v.end());
    int maxprofit=0,maxjobs=0;
    // min heap
    priority_queue<int,vector<int>,greater<int>> pq;

    for(int i=0;i<n;i++){
        if(v[i].first>pq.size()){
            pq.push(v[i].second);
        }else if(pq.size()>0 && pq.top()<v[i].second){
            pq.pop();
            pq.push(v[i].second);
        }
    }
    while(pq.size()>0){
        maxprofit+=pq.top();
        pq.pop();
        maxjobs++;
    }
    return {maxjobs,maxprofit};
}
int main(){
    vector<int> v3={3, 1, 2, 2},profit3={50, 10, 20, 30};
    vector<int> v1={4, 1, 1, 1},profit1={20, 10, 40, 30};
    vector<int> v2={2, 1, 2, 1, 1},profit2={100, 19, 27, 25, 15};
    for(auto &it:jobSequencing(v1,profit1)){
        cout<<it<<" ";
    }
    cout<<'\n';
    for(auto &it:jobSequencing(v2,profit2)){
        cout<<it<<" ";
    }
    cout<<'\n';
    for(auto &it:jobSequencing(v3,profit3)){
        cout<<it<<" ";
    }
    cout<<'\n';
}