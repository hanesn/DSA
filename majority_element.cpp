// The majority element is the element that appears more than ⌊n / 2⌋ times. 
// You may assume that the majority element always exists in the array.
#include<bits/stdc++.h>
using namespace std;
int moore_voting_algorithm(vector<int> &nums){
    int element,cnt=0;
    for(int i=0;i<nums.size();i++){
        if(cnt==0){
            element=nums[i];
        }
        if(nums[i]==element){
            cnt++;
        }else{
            cnt--;
        }
    }
    return element;
}
int main(){
    vector<int> arr={2,2,1,1,1,2,2};
    cout<<moore_voting_algorithm(arr);
}