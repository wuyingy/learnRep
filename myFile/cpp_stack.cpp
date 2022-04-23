#include <iostream>
#include <stack>

using namespace std;

int main()
{
	stack<int> mys;
	mys.push(0);
	mys.push(1);
	mys.push(2);
	mys.push(3);
	mys.push(4);
	for(int i=0;i<mys.size();i++)
	{
		cout<<mys.top()<<endl;
	}
        mys.pop();
	for(int i=0;i<mys.size();i++)
	{
		cout<<mys.top()<<endl;
	}

	return 0;
}
