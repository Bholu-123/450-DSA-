#include <bits/stdc++.h>
using namespace std;
//this will not handle duplicate in any of the array
void unionOfTwoArr(int n,int m,int a[],int b[])
{
    vector<int>ans;
    int i=0;
    int j=0;
    while(i<n && j<m)
    {
       if(a[i]<b[j])
       {
         ans.push_back(a[i]);
         i++;
       }
       else if(a[i]>b[j])
       {
         ans.push_back(b[j]);
         j++;
       }
       else
       {
         ans.push_back(a[i]);
         i++;j++;
       }
    }
    while(i<n)
    {
        ans.push_back(a[i]);
        i++;
    }
     
    while(j<m)
    {
        ans.push_back(b[j]);
        j++;
    }

    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }

}
int main() {
    #ifndef ONLINE_JUDGE 
      freopen("input.txt", "r", stdin); 
      freopen("output.txt", "w", stdout); 
    #endif
    int n,m;
    cin>>n>>m;
    int a[n];
    int b[m];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int j=0;j<m;j++)
    {
        cin>>b[j];
    }
    unionOfTwoArr(n,m,a,b);
}
