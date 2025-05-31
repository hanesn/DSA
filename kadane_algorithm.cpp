// find the subarray with the largest sum, and return its sum.
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int kadane(vector<int> &nums){
    // note here subarray can be of size 0 so min ans = 0
    // if empty subarray not allowed, take ans = INT_MIN
    ll currsum=INT_MIN,ans=0,n=nums.size();
    for(int i=0;i<n;i++){
        if(currsum+nums[i]>=nums[i]){
            currsum+=nums[i];
        }else{
            currsum=nums[i];
        }
        ans=max(ans,currsum);
    }
    return ans;
}
int main(){
    vector<int> arr={-2,1,-3,4,-1,2,1,-5,4};
    cout<<kadane(arr);
}