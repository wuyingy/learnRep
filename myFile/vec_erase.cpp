#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> vec;
	vec.push_back(0);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	cout<<*vec.erase(vec.begin())<<endl;
	cout<<vec.front()<<endl;

        return 0;
}
