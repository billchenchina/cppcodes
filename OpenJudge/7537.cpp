#include<cstdio>
#include<iostream>
using namespace std;
int main() 
{
int n,m;
m=0;
scanf("%d",&n);
if(n%3==0){
m++;
}
else
m=m;
if(n%5==0){
m++;
}
else
m=m;
if(m>1)
printf("YES");
else
printf("NO");
return 0;
}