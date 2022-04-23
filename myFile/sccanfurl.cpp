#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

int main()
{
	char url1[50],url2[30];
	char* url="https://\/\\/\www.baidu.com";
	int i=0;
	sscanf(url,"%[a-z]",url1);
	cout<<url1<<endl;

	sscanf(url,"https:%*[/\]",url2);
	strcat(url1,"://");
	strcat(url1,url2);
	cout<<url1<<endl;

	return 0;
}
