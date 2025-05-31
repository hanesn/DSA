#include<bits/stdc++.h>
using namespace std;
void quickSort(int a[],int lb,int ub)
{
    if(lb>=ub)
        return;
    int pivot=a[lb],start=lb,end=ub;
    while(start<end)
    {
        while(a[start]<=pivot)
            start++;
        while(a[end]>pivot)
            end--;
        if(start<end)
            swap(a[start],a[end]);
    }
    swap(a[lb],a[end]);
    quickSort(a,lb,end-1);
    quickSort(a,end+1,ub);
}
void display(int a[],int n)
{
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<'\n';
}
int main()
{
    int n,i;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    // int a[]={2,4,5,7,8,7,5,4,2,2,5};
    // display(a,n);
    quickSort(a,0,n-1);
    display(a,n);
}