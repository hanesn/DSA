#include<bits/stdc++.h>
using namespace std;
void Merge(int a[],int lb,int mid,int ub)
{
    int i=lb,j=mid+1;
    vector<int> b;
    while(i<=mid && j<=ub)
    {
        if(a[i]<=a[j])
        {
            b.push_back(a[i]);
            i++;
        }
        else
        {
            b.push_back(a[j]);
            j++;
        }
    }
    while(i<=mid)
    {
        b.push_back(a[i]);
        i++;
    }
    while(j<=ub)
    {
        b.push_back(a[j]);
        j++;
    }
    for(i=0;i<b.size();i++)
        a[i+lb]=b[i];
}
void mergeSort(int a[],int lb,int ub)
{
    if(lb>=ub)
        return;
    int mid=(lb+ub)/2;
    mergeSort(a,lb,mid);
    mergeSort(a,mid+1,ub);
    Merge(a,lb,mid,ub);
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
    display(a,n);
    mergeSort(a,0,n-1);
    display(a,n);
}