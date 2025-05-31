// need to sort arrays of just 0,1 and 2
#include<bits/stdc++.h>
using namespace std;
void dutch_national_flag_algorithm(vector<int> &nums){
    // [ 0 -> low-1 ] = all 0s
    // [ low -> mid-1 ] = all 1s
    // [ mid -> high ] = unsorted 0s/1s/2s
    // [ high+1 -> n-1 ] = all 2s
    // -------|------|-------|-------
    // 0      |l     |m     h|      n-1
    int n=nums.size();
    int low=0,mid=0,high=n-1;
    while(mid<=high){
        if(nums[mid]==0){
            swap(nums[low],nums[mid]);
            low++;
            mid++;
        }else if(nums[mid]==1){
            mid++;
        }else{
            swap(nums[mid],nums[high]);
            high--;
        }
    }
}
void display(vector<int> &arr){
    for(auto &it:arr){
        cout<<it<<" ";
    }
}
int main(){
    vector<int> arr={2,0,2,1,1,0};
    dutch_national_flag_algorithm(arr);
    display(arr);
}