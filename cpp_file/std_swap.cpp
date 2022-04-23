#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> myv={223,23,1,4,23,34,23,34,212};
	for(auto ite=myv.begin();ite!=myv.end();++ite)
	{
		cout<<*ite<<endl;
	}
	cout<<endl;
	std::swap(myv[0],myv[1]);
	for(auto ite=myv.begin();ite!=myv.end();++ite)
	{
		cout<<*ite<<endl;
	}
	return 0;
}
