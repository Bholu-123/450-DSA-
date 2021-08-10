//Maximum and minimum of an array using minimum number of comparisons
#include<bits/stdc++.h>
using namespace std;
//In this method, the total number of comparisons is 1 + 2(n-2) in the worst case and 
//1+ n – 2 in the best case.
//Naive approach
//If there is a single element in array then both min and max is that
//element and if there are  more than one element then 1st we make
//the min and max from 1st two element and then start traversing 
//from the 2nd element elememnt to last and if element is less than min then
//make that element min and if element is greater than max then make that elemnent
//max and if the element is neither greater than max nor less than min then skip that elemnt 
//and move forward
pair<int,int> getMinMax(int n,int a[])
{
	if(n==1)
	{
		pair<int,int>p;
		p.first=a[0];
		p.second=a[0];
		return p;
	}

	int currMin;
	int currMax;
	if(a[0]>a[1])
	{
		currMin=a[1];
		currMax=a[0];
	}
	else 
	{
		currMin=a[0];
		currMax=a[1];
	}
    
   for(int i=2;i<n;i++)
   {
   	if(a[i]>currMax)
   	{
   		currMax=a[i];
   	}
   	else if(a[i]<currMin)
   	{
   		currMin=a[i];
   	}
   }

   pair<int,int>p;
   p.first=currMin;
   p.second=currMax;
   return p;
}
//Optimize approach
//Total numbr of comparison
//If n is odd:3*(n-1)/2 
//If n is even:1+3*(n-1)/2 
//first we divide the whole array in  two part and recursively find the min and 
//max from both part and then compare the minimum and maximum from both part and 
//and get final minimum and maximum 
pair<int,int> getMinMaxOptimize(int low,int high,int a[])
{
   int min;
   int max;
   //if single element in array
	if(low==high)
	{
		pair<int,int>p;
		p.first=a[low];
		p.second=a[high];
		return p;
	}
	//two elements in array
	else if(high==low+1)
	{
    	if(a[low]>a[high])
	   {
		   min=a[high];
		   max=a[low];
	   }
	   else 
	   {
		   min=a[low];
		   max=a[high];
	   }

	   pair<int,int>p;
	   p.first=min;
	   p.second=max;
	   return p;
	}

	int mid=(low+high)/2;
	pair<int,int> mml=getMinMaxOptimize(low,mid,a);
	pair<int,int> mmR=getMinMaxOptimize(mid+1,high,a);
	int minL=mml.first;
	int maxL=mml.second;
	int maxR=mmR.second;
	int minR=mmR.first;
	if(minL<minR)
	{
		min=minL;
	}
	else
	{
		min=minR;
	}
	if(maxL>maxR)
	{
		max=maxL;
	}
	else
	{
		max=maxR;
	}
	pair<int,int>p;
	p.first=min;
	p.second=max;
	return p;
}
//Best approach
//No of comparison in best and optimize approach is same
// If n is odd then initialize min and max as first element. 
// If n is even then initialize min and max as minimum and maximum of the first two elements respectively. 
// For rest of the elements, pick them in pairs and compare their 
// maximum and minimum with max and min respectively.
pair<int,int> getMinMaxbest(int n,int a[])
{
	int min,max;
	int i;
	if(n%2==0)
	{
     if(a[0]>a[1])
     {
     	 min=a[1];
     	 max=a[0];
     }
     else
     {
     	 min=a[0];
     	 max=a[1];
     }

     i=2;
	}
	if(n%2==1)
	{
		min=a[0];
		max=a[0];
		i=1;
	}
   
   while(i<n-1)
   {
   	if(a[i]>a[i+1])
   	{
   		if(a[i]>max)
   		{
   			max=a[i];
   		}
   		else if(a[i+1]<min)
   		{
   			min=a[i+1];
   		}
   	}
   	else if(a[i]<a[i+1])
   	{
   		if(a[i]<min)
   		{
   			min=a[i];
   		}
   		else if(a[i+1]>max)
   		{
   			max=a[i+1];
   		}
   	}

   	 i=i+2;
   }
   
   pair<int,int>p;
	p.first=min;
	p.second=max;
	return p;
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
	  pair<int,int>op;
	  //op=getMinMax(n,a);
	  int low=0;
	  int high=n-1;
	  op=getMinMaxbest(n,a);
	  cout<<"MIN::"<<op.first<<endl;
	  cout<<"MAX::"<<op.second<<endl;
	  return 0;
}