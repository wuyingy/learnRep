#include <iostream>
#include <vector>

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
        mystack.push(0);
        mystack.push(1);	
        mystack.push(2);
        mystack.push(3);
        mystack.push(4);	
        mystack.push(5);
	mystack.display();

        mystack.pop();
        mystack.display();
        cout<<mystack.peek()<<endl;	

	return 0;
}
