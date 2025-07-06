#include<bits/stdc++.h>
using namespace std;
// logic - have a deque of size k and store in increasing order of values
// example for the first 3 element of v
// front                back
// ----------------------
//     3           -1
// ----------------------
// since numbers smaller of left would never contribute to maximum
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> q;
    vector<int> ans;
    int n=nums.size();
    for(int i=0;i<k;i++){
        while(q.size()>0 && q.back()<nums[i]) q.pop_back();
        q.push_back(nums[i]);
    }
    ans.push_back(q.front());
    if(nums[0]==q.front()) q.pop_front();
    for(int i=k;i<n;i++){
        while(q.size()>0 && q.back()<nums[i]) q.pop_back();
        q.push_back(nums[i]);
        ans.push_back(q.front());
        if(nums[i-k+1]==q.front()) q.pop_front();
    }
    return ans;
}
int main(){
    vector<int> v={1,3,-1,-3,5,3,6,7};
    vector<int> ans=maxSlidingWindow(v,3);
    for(auto &it:ans){
        cout<<it<<" ";
    }
}