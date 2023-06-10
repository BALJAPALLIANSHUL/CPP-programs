#include<bits/stdc++.h>
using namespace std;
void merge(int l,int mid,int r, int arr[])
{
	int l_sz = mid-l + 1;
	int r_sz = r - mid;
	int *L = new int[l_sz+1];
	int *R = new int[r_sz+1];
	for(int i = 0;i<l_sz;i++)
	{
		L[i] = arr[l + i]; 
	}
	for(int i = 0;i<r_sz;i++)
	{
		R[i] = arr[mid + i + 1]; 
	}
	int l_i = 0,r_i = 0;
	L[l_sz] = R[r_sz] = INT_MAX;
	for(int i = l;i<=r;i++)
	{
		if(L[l_i] <= R[r_i])
		{
			arr[i] = L[l_i];
			l_i++;
		}
		else{
			arr[i] = R[r_i];
			r_i++;
		}
	}
	delete[] L;
	delete[] R;
}
void mergesort(int arr[],int l,int r)
{
	if(l>=r) 
		return;
	int mid = l + (r-l)/2;
	mergesort(arr,l,mid);
	mergesort(arr,mid+1,r);
	merge(l,mid,r,arr);
}
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);
	#endif
	int n;
	cin>>n;
	int *arr = new int[n];
	
	for(int i = 0;i<n;i++)
	{
		cin>>arr[i];
	}
	mergesort(arr,0,n-1);
	for(int i = 0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}