#include<bits/stdc++.h>
using namespace std;

// logic: for each element - we need next smaller element to its left and right
int largestRectangleArea(vector<int>& heights) {
    int n=heights.size();
    vector<int> prefix(n,-1),suffix(n,n);
    stack<int> stk;

    // computing nse for left
    for(int i=0;i<n;i++){
        while(stk.size()>0 && heights[stk.top()]>=heights[i]) stk.pop();
        if(stk.size()>0) prefix[i]=stk.top();
        stk.push(i);
    }

    // just emptying the stack to use to compute nse for right
    while(stk.size()>0) stk.pop();

    // computing nse for right
    for(int i=n-1;i>=0;i--){
        while(stk.size()>0 && heights[stk.top()]>=heights[i]) stk.pop();
        if(stk.size()>0) suffix[i]=stk.top();
        stk.push(i);
    }

    int ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,(suffix[i]-prefix[i]-1)*heights[i]);
    }
    return ans;
}
int main(){
    vector<int> v={2,1,5,6,2,3};
    cout<<largestRectangleArea(v);
}