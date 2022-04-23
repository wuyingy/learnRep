#include <iostream>
#include <array>

using namespace std;

template<typename T,int cap=10>
class arrQueue{
	private:
		array<T,cap> arr;
		int head,tail;
	public:
		arrQueue(){
			head=tail=0;
		}
		bool empty(){
			return arr.empty();
		}
		int getsize(){
			return arr.size();
		}
		void enqueue(T v){
			arr[tail]=v;
			tail=(tail+1)%arr.size();
		}
		T dequeue(){
			if(empty())
			{
				cout<<"queue ia empty"<<endl;
				exit(0);
			}
			T del=arr[head];
			arr[head]=NULL;
			head=(head+1)%arr.size();
			return del;
		}
		T getFirst(){
			return arr[head];
		}
};
int main()
{
	arrQueue<int> arrq;
	cout<<arrq.empty()<<endl;
	arrq.enqueue(0);
	arrq.enqueue(1);
	arrq.enqueue(2);
	arrq.enqueue(3);
	cout<<arrq.getFirst()<<endl;
	cout<<arrq.dequeue()<<endl;
	cout<<arrq.getFirst()<<endl;
	cout<<arrq.getsize()<<endl;

	return 0;
}
