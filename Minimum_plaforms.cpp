// You are given the arrival times arr[] and departure times dep[] of all trains that 
// arrive at a railway station on the same day. Your task is to determine the minimum 
// number of platforms required at the station to ensure that no train is kept waiting.
// At any given time, the same platform cannot be used for both the arrival of one train 
// and the departure of another. Therefore, when two trains arrive at the same time, or 
// when one arrives before another departs, additional platforms are required to accommodate both trains.

// https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

#include<bits/stdc++.h>
using namespace std;
int findPlatform(vector<int>& arr, vector<int>& dep) {
    sort(arr.begin(),arr.end());
    sort(dep.begin(),dep.end());
    int i=0,j=0,n=arr.size(),currstation=0;
    int ans=0;
    while(i<n && j<n){
        if(arr[i]<=dep[j]){
            currstation++;
            i++;
        }else{
            currstation--;
            j++;
        }
        ans=max(ans,currstation);
    }
    return ans;
}
int main(){
    vector<int> arr={900, 940, 950, 1100, 1500, 1800};
    vector<int> dept={910, 1200, 1120, 1130, 1900, 2000};
    cout<<findPlatform(arr,dept);
}