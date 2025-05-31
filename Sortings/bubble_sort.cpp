#include<bits/stdc++.h>
using namespace std;
void bubbleSort(int a[],int n)
{
    bool flag;
    for(int i=0;i<n;i++)
    {
        flag=1;
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j+1]<a[j])
            {
                swap(a[j],a[j+1]);
                flag=0;
            }
        }
        if(flag)
            break;
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
    // int a[n];
    int a[]={2,4,5,7,8,7,5,4,2,2,5};
    // for(i=0;i<n;i++)
    //     cin>>a[i];
    display(a,11);
    bubbleSort(a,11);
    display(a,11);
}