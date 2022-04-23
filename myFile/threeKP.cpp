#include <iostream>
#include <vector>

using namespace std;

void sort(vector<int>& myv,int lo,int hi)
{
	if(lo>=hi) return;
	int i=lo,less=lo,great=hi;
	int pivot=myv[hi];
	while(i<=great)
	{
		if(myv[i]<pivot)
		{
			std::swap(myv[i],myv[less]);
			++i;
			++less;
		}else if(myv[i]>pivot)
		{
			std::swap(myv[i],myv[great]);
			--great;
		}else
		{
			++i;
		}
	}
	sort(myv,lo,less-1);
	sort(myv,great+1,hi);
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
	vector<int> myv={12,23,3,468,45,2,1,3,5434,3,77,3};
	display(myv);
	sort(myv);
	display(myv);
	return 0;
}
