#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

template<typename T>
class myStack
{
	private:
		vector<T> myv;
	public:
		myStack(){}
		bool empty()
		{
			return myv.empty();
		}
		int getSize()
		{
			return myv.size();
		}
		void push(T v)
		{
			myv.push_back(v);
		}
		void pop()
		{
			myv.pop_back();
		}
		T peek()
		{
			return myv.back();
		}
		void display()
		{
			for(int i=myv.size()-1;i>=0;--i)
			{
				cout<<myv[i]<<endl;
			}
			cout<<endl;
		}
};

int main()
{
	myStack<int> mystack;
	time_t t1=time(NULL);
	for(int i=0;i<100;i++)
		mystack.push(i);
	time_t t2=time(NULL);
	cout<<t2-t1<<endl;

	return 0;
}
