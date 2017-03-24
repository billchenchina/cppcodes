#include<iostream>
#include<cstdio>
using namespace std;

int main() {
int n,g=0,g1,y=0,y1,t=0,t1,all;
scanf("%d",&n);
for(int i=1;i<=n;i++){
    scanf("%d%d%d",&g1,&y1,&t1);
    g=g+g1;
    y=y+y1;
    t=t+t1;
} 
all=g+y+t;
printf("%d %d %d %d",g,y,t,all);
return 0;
}