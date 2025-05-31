#include<bits/stdc++.h>
using namespace std;
void insertionSort(int *a,int n)
{
    int key;
    for(int i=1;i<n;i++)
    {
        key=a[i];
        for(int j=i-1;j>=0;j--)
        {
            if(a[j]>key)
                swap(a[j],a[j+1]);
            else
            {
                a[j+1]=key;
                break;
            }
        }
    }
}
void display(int a[],int n)
{
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<"\n";
}
int main()
{
    int n,i;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    display(a,n);
    insertionSort(a,n);
    display(a,n);
}