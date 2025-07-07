#include<bits/stdc++.h>
using namespace std;
int binaryExponentiation(int x,int y){
    if(y==0) return 1;
    int ans=binaryExponentiation(x,y/2);
    if(y%2==0){
        return ans*ans;
    }else{
        return x*ans*ans;
    }
}
int main(){
    cout<<binaryExponentiation(2,10);
}