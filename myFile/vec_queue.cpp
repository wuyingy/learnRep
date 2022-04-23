#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class vecQueue
{
	private:
		vector<T> vec;
	public:
		vecQueue(){}
		vecQueue(T v){
			vec.push_back(v);
		}
		bool empty()
		{
			return vec.empty();
		}
		int getSize()
		{
			return vec.size();
		}
		void enqueue(T v){
			vec.push_back(v);
		}
		T dequeue(){
		       return *vec.erase(vec.begin());
		}
		T getFirst(){
			return vec.front();
		}
};

int main()
{
	vecQueue<int> vQueue;
	vQueue.enqueue(1);
	vQueue.enqueue(2);
	vQueue.enqueue(3);
	vQueue.enqueue(4);
	cout<<vQueue.dequeue()<<endl;
	cout<<vQueue.getFirst()<<endl;

	return 0;
}
