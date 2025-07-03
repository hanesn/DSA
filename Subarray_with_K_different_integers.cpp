// checkout below for leetcode question
// https://leetcode.com/problems/subarrays-with-k-different-integers/description/
// this is a type of 2 pointer problem where we need to find count of subarrays where condition=k
// idea is to use 2 pointer as ans = (condition<=k - condition<=k-1)
#include<bits/stdc++.h>
using namespace std;
// return number of sub arrays with sum<=k
    int func(vector<int> &nums,int k){
    unordered_map<int,int> mp;
    int low=0,high=0,n=nums.size(),ans=0;
    while(high<n){
        mp[nums[high]]++;
        while(mp.size()>k){
            mp[nums[low]]--;
            if(mp[nums[low]]==0) mp.erase(nums[low]);
            low++;
        }
        ans+=high-low+1;
        high++;
    }
    return ans;
}
int subarraysWithKDistinct(vector<int>& nums, int k) {
    return func(nums,k)-func(nums,k-1);
}
int main(){
    vector<int> v={1,2,1,2,3};
    cout<<subarraysWithKDistinct(v,2);
}