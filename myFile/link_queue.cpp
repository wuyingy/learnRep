#include <iostream>
#include <list>

using namespace std;

template<typename T>
class linkQueue{
	private:
		list<T> listQ;
	public:
		linkQueue(){}
		linkQueue(T v){
			listQ.emplace_front(v);
		}
		bool empty(){
			return listQ.empty();
		}
		int getSize(){
			return listQ.size();
		}
		void enqueue(T v){
			listQ.emplace_front(v);
		}
		T dequeue(){
			return *listQ.erase(--listQ.end());
		}
		T getFirst(){
			return listQ.back();
		}
};
int main(){
	linkQueue<int> linkq;
	linkq.enqueue(0);
	linkq.enqueue(1);
	linkq.enqueue(2);
	linkq.enqueue(3);
	cout<<linkq.getFirst()<<endl;
	cout<<linkq.dequeue()<<endl;
	cout<<linkq.getFirst()<<endl;

	return 0;
}
