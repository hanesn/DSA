#include<bits/stdc++.h>
using namespace std;
void display(int a[],int n)
{
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<'\n';
}
void heapify(int a[],int n,int idx)
{
    int largest=idx,left=2*idx+1,right=2*idx+2;
    if(left<n && a[left]>a[largest])
        largest=left;
    if(right<n && a[right]>a[largest])
        largest=right;
    if(idx!=largest)
    {
        swap(a[idx],a[largest]);
        heapify(a,n,largest);
    }
}
void heapSort(int a[],int n)
{
    for(int i=n/2-1;i>=0;i--)
        heapify(a,n,i);
    display(a,10);
    for(int i=n-1;i>0;i--)
    {
        swap(a[0],a[i]);
        heapify(a,i,0);
    }
}
int main()
{
    int i;
    int a[10]={3,1,4,1,5,9,2,5,8,7};
    display(a,10);
    heapSort(a,10);
    display(a,10);
}