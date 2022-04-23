#include <iostream>

using namespace std;

template<class T>
struct node
{
	T data;
	node* prev=nullptr;
	node* next=nullptr;
	node(){}
	node(T v):data(v){}
	node(T v,node<T>* p,node<T>* n):data(v),prev(p),next(n){}
};
template<typename T>
class doubleList
{
	private:
		int size;
		node<T>* first=nullptr;
	        node<T>* last=nullptr;
	public:
		doubleList()
		{
			first=nullptr;
			last=nullptr;
			size=0;
		}
		doubleList(T v)
		{
			first=new node<T>(v);
			last=first;
			size=1;
		}
		node<T>* createNode(T v)
		{
			return (node<T>*)new node<T>(v);
		}
		void addFirst(T v)
		{
			node<T>* tp=createNode(v);
			if(first==nullptr)
				last=tp;
			else
			{
				tp->next=first;
				first->prev=tp;
			}
			first=tp;
			size++;
		}
		void addLast(T v)
		{
			node<T>* tp=createNode(v);
			if(last==nullptr)
				first=tp;
			else
			{
				last->next=tp;
				tp->prev=last;
			}
			last=tp;
			size++;
		}
		node<T>* find(int index)
		{
			if(index<0||index>=size)
			{
				cout<<"Index overflow."<<endl;
				exit(0);
			}
			if(index==0)
				return first;
			else if(index==(size-1))
				return last;
			else if(index<size/2)
			{
				node<T>* curr=first;
				for(int i=0;i<index;++i)
				{
					curr=curr->next;
				}
				return curr;
			}else
			{
				node<T>* curr=last;
				for(int i=size-1;i>=index;--i)
				{
					curr=curr->prev;
				}
				return curr;
			}
		}
	        //add node one by one
		void addNode(int index,T v)
		{
			if(index<0||index>size)
			{
				cout<<"Index overflow."<<endl;
				exit(0);
			}
			if(index==0)
			{
				addFirst(v);
			}else if(index==size)
			{
				addLast(v);
			}
			else
			{
				node<T>* getNode=find(index);
				node<T>* creNode=createNode(v);
				node<T>* prev=getNode->prev;
				prev->next=creNode;
				creNode->next=getNode;
				getNode->prev=creNode;
			}
		}	

		int getsize()
		{
			return size;
		}
		bool empty()
		{
			return size==0?true:false;
		}
		T at(int index)
		{
			node<T>* getNode=find(index);
			return getNode->data;
		}
		void reset(int index,T v)
		{
			node<T>* getNode=find(index);
			if(getNode)
			{
			    getNode->data=v;	
			}
		}
		void erase(int index)
		{
			node<T>* getNode=find(index);
			if(getNode)
			{
				if(getNode==first)
				{
					getNode->next->prev=nullptr;
					first=first->next;
					delete getNode;
				}else if(getNode==last)
			        {
					getNode->prev->next=nullptr;
					last=getNode->prev;
					delete getNode;
				}else
				{
					getNode->prev->next=getNode->next;
					getNode->next->prev=getNode->prev;
					delete getNode;
				}
			}
		}
		void display()
		{
			node<T>* curr=first;
			for(;curr!=nullptr;)
			{
				cout<<curr->data<<endl;
				curr=curr->next;
			}
			cout<<endl;
		}
};
template<typename T>
class linkStack
{
	private:
		doubleList<T> stackList;
	public:
		linkStack(T v)
		{
			stackList.addFirst(v);
		}
		bool empty()
		{
			return stackList.empty();
		}
		int stackSize()
		{
			return stackList.getsize();
		}
		void push(T v)
		{
			stackList.addFirst(v);
		}
		void pop()
		{
			stackList.erase(stackList.getsize()-1);
		}
		T peek()
		{
			return stackList.at(0);
		}
		void display()
		{
			stackList.display();
		}
};
int main()
{
	linkStack<int> mys(0);
	mys.push(1);
	mys.push(2);
	mys.push(3);
	mys.push(4);
	mys.push(5);
	mys.display();

	mys.pop();
	mys.display();
	cout<<mys.peek()<<endl;

	return 0;
}
