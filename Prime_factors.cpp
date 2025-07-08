#include<bits/stdc++.h>
using namespace std;
vector<int> findPrimeFactor(int n){
    vector<int> ans;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            ans.push_back(i);
            while(n%i==0){
                n/=i;
            }
        }
    }
    if(n>1){
        ans.push_back(n);
    }
    return ans;
}
int main(){
    vector<int> ans=findPrimeFactor(13);
    for(auto i:ans){
        cout<<i<<" ";
    }
}