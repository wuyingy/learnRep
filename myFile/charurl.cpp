#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	char url[50];
	int i=0;
	cin>>url;
	url1=url.substr(0,6);
	cout<<url1<<endl;
	for(i=6;i<url.size();++i)
	{
		if(url[i]!='/'||url[i]!='\\')
			break;
	}
	url2=url.substr(i);
	url=url1+"//"+url2;
	cout<<url<<endl;

	return 0;
}
