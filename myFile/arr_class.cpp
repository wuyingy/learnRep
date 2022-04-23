#include <iostream>
#include <sstream>
using namespace std;

template<typename T>
class arrClass
{
	private:
		int size;
		int capacity;
		T* data;
		void resize()
		{
			T* newArr=new T[capacity*2];
			for(int i=0;i<size;++i)
				newArr[i]=data[i];
			capacity*=2;
			this->data=newArr;
		}
	public:
		arrClass(int num)
		{
			data=new T[num];
			capacity=num;
			size=0;
		}
		arrClass()
		{
			data=new T[100];
			capacity=100;
			size=0;
		}
		int getsize()
		{
			return size;
		}
		bool empty()
		{
			if(size==0)
				return true;
			else
				return false;
		}
		void push_back(int n)
		{
			if(size>=capacity)
				resize();
			data[size++]=n;
		}
		void add(T n,int index)
		{
			if(size>=capacity)
				cout<<"Array filled up."<<endl;
			if(index<0||index>capacity)
				throw "Index overflow.";
			for(int j=size-1;j>=index;--j)
			{
				data[j+1]=data[j];
			}
			data[index]=n;
			size++;
		}
		int find(T n)
		{
			for(int i=0;i<capacity;++i)
			{
				if(data[i]==n)
					return i;
			}
			return -1;
		}
		T at(int index)
		{
			if(index<0||index>capacity||size>=capacity)
				throw "Index overflow.";
			return data[index];
		}
	        void erase(T n)
		{
			for(int i=0;i<capacity;++i)
			{
				if(data[i]==n)
				{
					for(int j=i;j<capacity;++j)
					{
						data[j]=data[j+1];
					}
					size--;
				}
			}
		}
		~arrClass()
		{
			delete data;
		}
};
int main()
{
	arrClass<int> mya(4);
	mya.add(10,0);
	//cout<<mya.empty()<<endl;
	//cout<<mya.at(0)<<endl;
	mya.add(555,2);
	//cout<<mya.at(2)<<endl;
	//mya.erase(555);
	//cout<<mya.at(2)<<endl;
	mya.add(12,1);
	mya.add(3,3);
	mya.push_back(111);
	int i=mya.find(111);
	cout<<i<<endl;

	return 0;
}
