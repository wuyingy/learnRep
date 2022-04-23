#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	string str="1234567";
	cout<<str.at(1)<<endl;
	str.erase(0,3);
	cout<<str<<endl;
	return 0;
}
