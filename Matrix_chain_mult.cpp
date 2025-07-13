#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
int func(int i,int j,vector<int> &arr){
    if(i==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int mini=1e9;
    for(int k=i;k<=j-1;k++){
        int steps=arr[i-1]*arr[k]*arr[j]+func(i,k,arr)+func(k+1,j,arr);
        mini=min(mini,steps);
    }
    return dp[i][j]=mini;
}
int matrixMultiplication(vector<int> &arr) {
    return func(1,arr.size()-1,arr);
}
int main(){
    vector<int> arr = {2, 1, 3, 4};
    dp.resize(arr.size()+1,vector<int> (arr.size()+1,-1));
    cout << matrixMultiplication(arr);
}