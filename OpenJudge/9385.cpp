#include<cstdio>
#include<iostream>
using namespace std;
int main(){
int n,x,y,l;
scanf("%d%d%d",&n,&x,&y);
if(y%x==0){
    l=n-y/x;
}
else{
    l=n-y/x-1;
}
if(l<0)
l=0; 
printf("%d",l);
return 0;
}