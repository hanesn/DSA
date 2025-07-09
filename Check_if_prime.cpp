#include<bits/stdc++.h>
using namespace std;
bool isPrime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return false; // n is divisible by i, hence not prime
        }
    }
    return true;
}
int main(){
    cout<<isPrime(81)<<"\n"; // Expected output: 1 (true)
}