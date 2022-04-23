#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	string url;
	//url="https://\/\\/\www.baidu.com";
	//url="https:///\/www.baidu.com"
	url="https:/\\\\//\/\/www.baidu.com";
	cout<<url<<""<<url.size()<<endl;
	int i=0;
	for(i=6;i<url.size();++i)
	{
		if(url[i]=='\\'||url[i]=='/')
			url.erase(i,1);
	}
	cout<<url<<endl;
	for(i=6;i<url.size();++i)
	{
		if(url[i]=='\\'||url[i]=='/')
			url.erase(i,1);
	}
	cout<<url<<endl;
	const char agu='/';
	url.insert(6,&agu);
	url.insert(6,&agu);
	cout<<url<<endl;

	return 0;
}
