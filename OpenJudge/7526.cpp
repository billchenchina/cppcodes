#include<cstdio>
#include<iostream>
using namespace std;
int main(){
int a,b,c,i;
i=0;
scanf("%d%d%d",&a,&b,&c);
if(a+b>c)
i++;
if(a+c>b)
i++;
if(b+c>a)
i++;
if(i==3)
printf("yes");
else
printf("no");

return 0;
}