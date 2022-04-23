#include <iostream>
#include <array>

using namespace std;
int temp[8];
void display(array<int,8>& arr)
{
	for(int i=0;i<arr.size();++i)
		cout<<arr[i]<<endl;
	cout<<endl;
}
void merge(array<int,8>& arr,int left,int mid,int right)
{
	int i=left,j=mid+1,t=left;
	while(i<=mid&&j<=right)
	{
		if(arr[i]<arr[j])
		{
			temp[t++]=arr[i++];
		}
		else
		{
			temp[t++]=arr[j++];
		}
	}
	while(i<=mid)
	{
		temp[t++]=arr[i++];
	}
	while(j<=right)
	{
		temp[t++]=arr[j++];
	}	
	
	for(int y=left;y<t;y++)
	{
		arr[left++]=temp[y];//Pay attention to this
	}
}
void sort(array<int,8>& arr,int left,int right)
{
	//The end condition:
	if(left==right)
		return;
	int mid=(left+right)/2;
	sort(arr,left,mid);
	sort(arr,mid+1,right);
	//continue to split(拆分) to bottom
	//when back,this layer is the least(最小的)
	merge(arr,left,mid,right);
}
void sort(array<int,8>& arr)
{
	if(arr.size()<2) return;
	sort(arr,0,arr.size()-1);
}
int main()
{
	array<int,8> arr={11,23,2,321,34,5134,1,44};
	display(arr);
	sort(arr);
	display(arr);
	return 0;
}
