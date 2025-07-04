// sieve of Eratosthenes algorithm to find all prime numbers up to a given number N
// T(O(n log (log n))), S(O(n))
#include<bits/stdc++.h>
using namespace std;
vector<int> isPrime;
void findPrimes(int n){
    for(int i=2;i*i<=n;i++){
        if(isPrime[i]){
            for(int j=i*i;j<=n;j+=i){
                isPrime[j] = false; // Marking multiples of i as non-prime
            }
        }
    }
}
int main() {
    int n=1000;
    isPrime.resize(n+1, true);
    isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime numbers
    findPrimes(n);
    for(int i=2;i<=n;i++){
        if(isPrime[i]){
            cout<<i<<" ";
        }
    }
    cout<<endl;
    return 0;
}