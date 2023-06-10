#include<bits/stdc++.h>
using namespace std;
void print_array(int n,vector<int>& arr)
{
	for(int i = 0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int partition(int low,int high,vector<int>& arr)
{
	int pivot_index = low;
	int i = low+1;
	int j = high;
	while(i<j)
	{
		while(arr[i]<=arr[pivot_index]){	i++;	}
		while(arr[j]>arr[pivot_index]){	j--;	}
		swap(arr[i],arr[j]);
	}
	swap(arr[low],arr[j]);
	return j;
}
void quicksort(int low,int high, vector<int>& arr)
{
	if(low<high)
	{
		int p = partition(low,high,arr);
		quicksort(low,p-1,arr);
		quicksort(p+1,high,arr);
	}
}
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);
	#endif
	int n,k;
	cin>>n;
	vector<int> v(n);
	for(int i = 0;i<n;i++)
	{
		cin>>k;
		v.push_back(k);
	}
	cout<<"before sorting: ";
	print_array(n,v);
	quicksort(0,n-1,v);
	cout<<"after sorting: ";
	print_array(n,v);
}