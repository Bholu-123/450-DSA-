#include<bits/stdc++.h>
using namespace std;
void sort012(int a[], int n)
{
    int low=0;
    int high=n-1;
    int ptr=0;
    while(ptr<=high)
    {
        if(a[ptr]==0)
        {
            swap(a[ptr],a[low]);
            low++;
            ptr++;
        }
        else if(a[ptr]==2)
        {
            swap(a[high],a[ptr]);
            high--;
        }
        else
        {
            ptr++;
        }
    } 
}
int main()
{
	#ifndef ONLINE_JUDGE 
      freopen("input.txt", "r", stdin); 
      freopen("output.txt", "w", stdout); 
    #endif
    int n;
    cin>>n;
    int a[n+1];
    for(int i=0;i<n;i++)
    {
      cin>>a[i];
    }
    
    sort012(a,n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}