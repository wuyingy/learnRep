#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& myv,int lo,int hi)
{
	int less=lo,great=lo;
	int pivot=myv[hi];
	for(;great<=hi-1;++great)
	{
		if(myv[great]<pivot)
		{
			std::swap(myv[less++],myv[great]);
		}
	}
	std::swap(myv[less],myv[hi]);

	return less;
}
void sort(vector<int>& myv,int lo,int hi)
{
	if(lo>=hi) return;
	int p=partition(myv,lo,hi);
	sort(myv,lo,p-1);
	sort(myv,p+1,hi);
}
void sort(vector<int>& myv)
{
	if(myv.size()<=1) return;
	sort(myv,0,myv.size()-1);
}

void display(vector<int>& myv)
{
	for(auto ite=myv.begin();ite!=myv.end();++ite)
	{
		cout<<*ite<<endl;
	}
	cout<<endl;
}

int main()
{
	vector<int> myv={12,23,3,468,45,2,1,4376,5434,342,77,222};
	display(myv);
	sort(myv);
	display(myv);
	return 0;
}
