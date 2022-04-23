#include<stdio.h>  
void main()  
{  
    char arr1[3]={'A','B','C'};  
    char arr2[2]={'D','E'};  
    char arr3[3]={'F','G','H'};  
    int a[][2]={0,0,0,0,0,0,0,0,0,0,0,0};  
    int b[][2]={0,0,0,0,0,0,0,0,0,0,0,0};  
    int i,j,m,n,k1 = 0,k2 = 0,t=0;   
    char s,d,k;       
    while(1)  
    {  
        printf("请输入源地址和目的地址：");  
        scanf("%c%c",&s,&d);  
        printf("\n");  
        for(i=0;i<3;i++){  
            if(arr1[i]==s)  
                m=1;  
        }  
        for(i=0;i<2;i++){  
            if(arr2[i]==s)  
                m=2;  
        }  
        for(i=0;i<3;i++){  
            if(arr3[i]==s)  
                m=3;  
        }  
        switch(m)  
        {  
        case 1:  
            {  
                for(i=0;i<k1;i++){  
                    if(a[i][0]==s)  
                    {break;}  
                }  
                if(i==k1) {a[k1][0]=s;a[k1][1]=m;k1++;}//没有记录，在网桥数组中插入源地址  

                for(i=0;i<k1;i++)//查找网桥数组中是否有目的地址  
                {  
                    if(a[i][0]==d)  
                    {  
                        n=a[i][1]; break;  
                    }  
                }  

                if(i==k1) printf("网桥1中没有目的记录%c，向右转发\n",d);//不含有，转发  
                else  
                {  
                    if(m==n){  
                        printf("网桥1丢弃\n");t=1;  
                    }//含有且在同在网段丢弃  
                    else  
                        printf("不在同一网段，网桥1向右转发\n");//含有不在同一网段转发  
                }  

                if(t!=1) //不在同一网段时  
                {  
                    for(i=0;i<k1;i++)  
                        if(b[i][0]==s) {break;}  
                        if(i==k1) {b[k2][0]=s;b[k2][1]=m;k2++;}//没有记录，在网桥数组中插入源地址  
                        for(i=0;i<k1;i++)//查找网桥数组中是否有目的地址  
                        {if(b[i][0]==d) {n=b[i][1]; break;}}  
                        if(i==k2) printf("网桥2中没有目的记录%c，向右转发\n",d);//不含有，转发  
                        else  
                        {  
                            if(m==n) printf("网桥2丢弃\n");//含有且在同在网段丢弃  
                            else printf("不在同一网段，网桥2向右转发\n");//含有不在同一网段转发  
                        }  
                }  
                break;  
            }  
        case 2:  
            {  
                //向左转发  
                for(i=0;i<k1;i++)  
                    if(a[i][0]==s) {break;}  
                    if(i==k1) {a[k1][0]=s;a[k1][1]=m;k1++;}//没有记录，在网桥数组中插入源地址  

                    for(i=0;i<k1;i++)//查找网桥数组中是否有目的地址  
                    {if(a[i][0]==d) {n=a[i][1]; break;}}  

                    if(i==k1) printf("网桥1中没有目的记录%c，向左转发\n",d);//不含有，转发  
                    else  
                    {  
                        if(m==n) printf("网桥1丢弃\n");//含有且在同在网段丢弃  
                        else printf("不在同一网段，网桥1向左转发\n");//含有不在同一网段转发  
                    }  
                    //向右转发  
                    for(i=0;i<k2;i++)  
                        if(b[i][0]==s) {break;}  
                        if(i==k2) {b[k2][0]=s;b[k2][1]=m-1;k2++;}//没有记录，在网桥数组中插入源地址  

                        for(i=0;i<k2;i++)//查找网桥数组中是否有目的地址  
                        {if(b[i][0]==d) {n=b[i][1]; break;}}  
                        if(i==k2) printf("网桥2中没有目的记录%c，向右转发\n",d);//不含有，转发  
                        else  
                        {  
                            if(1==n) printf("网桥2丢弃\n");//含有且在同在网段丢弃  
                            else printf("不在同一网段，网桥2向右转发\n");//含有不在同一网段转发  
                        }  
                        break;  
            }  
        case 3:  
            {  
                for(i=0;i<k2;i++)  
                    if(b[i][0]==s) {break;}  
                    if(i==k2) {b[k2][0]=s;b[k2][1]=m+1;k2++;}//没有记录，在网桥数组中插入源地址  
                    for(i=0;i<k2;i++)//查找网桥数组中是否有目的地址  
                    {if(b[i][0]==d) {n=b[i][1]; break;}}  
                    if(i==k2) printf("网桥2中没有目的记录，向左转发\n");//不含有，转发  
                    else  
                    {  
                        if(2==n) {printf("网桥2丢弃\n");t=1;}//含有且在同在网段丢弃  
                        else printf("不在同一网段，网桥2向左转发\n");//含有不在同一网段转发  
                    }  

                    if(t!=1)//不在同一网段时  
                    {  

                        for(i=0;i<k1;i++)  
                            if(a[i][0]==s) {break;}  
                            if(i==k1) {a[k1][0]=s;a[k1][1]=m+1;k1++;}//木有记录，在网桥数组中插入源地址  
                            for(i=0;i<k1;i++)//查找网桥数组中是否有目的地址  
                            {if(a[i][0]==d) {n=a[i][1]; break;}}  
                            if(i==k1) printf("网桥1中没有目的记录%c，向左转发\n",d);//不含有，转发  
                            else  
                            {  
                                if(2==n) printf("网桥1丢弃\n");//含有且在同在网段丢弃  
                                else printf("不在同一网段，网桥1向左转发\n");//含有不在同一网段转发  
                            }  
                    }  
                    break;  

            }  
        default: ;  
    }  

    putchar('\n');  
    printf("网桥1\n");  
    printf("--------\n");  
    for(i=0;i<k1;i++)  
    {printf("  %c  ",a[i][0]);  
    printf("%d  ",a[i][1]);  
    putchar('\n');  
    }  
    printf("--------\n");  
    printf("网桥2\n");  
    printf("--------\n");  
    for(i=0;i<k2;i++)  
    {printf("  %c  ",b[i][0]);  
    printf("%d  ",b[i][1]);  
    putchar('\n');  
    }  
    printf("-------\n");  
    scanf("%c",&k);  
      }  

}  
