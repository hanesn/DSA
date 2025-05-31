#include<bits/stdc++.h>
using namespace std;
void selectionSort(int a[],int n)
{
    int mini,idx;
    for(int i=0;i<n-1;i++)
    {
        mini=a[i],idx=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<mini)
            {
                mini=a[j];
                idx=j;
            }
        }
        swap(a[i],a[idx]);
    }
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
    selectionSort(a,n);
    display(a,n);
}