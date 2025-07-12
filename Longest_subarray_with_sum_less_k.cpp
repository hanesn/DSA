// return length 0f longest subarray with sum<=k
#include<bits/stdc++.h>
using namespace std;
int longestSubarray(vector<int> &arr,int k){
    int n=arr.size();
    int left=0, right=0, sum=0, maxLength=0;
    while(right<n){
        sum+=arr[right++];
        while(sum>k){
            sum-=arr[left++];
        }
        if(left>right){
            right=left;
        }
        maxLength=max(maxLength,right-left);
    }
    return maxLength;
}
int main(){
    vector<int> arr={2,5,1,7,10};
    cout<<longestSubarray(arr, 14);
}