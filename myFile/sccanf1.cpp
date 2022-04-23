#include <iostream>
#include <stdio.h>

using namespace std;
int main()
{
	char* p="get http://www.baidu.com/dir/defualt http/1.1";
        char filepath[100];
        sscanf(p,"%s",filepath);
        cout<<filepath<<endl;
        sscanf(p,"get %s",filepath);
        cout<<filepath<<endl;
        sscanf(p,"get http://www.baidu.com/dir/defualt %s",filepath);
        cout<<filepath<<endl;
        return 0;
}
