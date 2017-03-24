#include<cstdio>
#include<iostream>
using namespace std;
int main(){
int x,y;
scanf("%d%d",&x,&y);
if(x>1){
    printf("no");
}
else if(x<-1){
    printf("no");
}
else if(y>1){
    printf("no");
}
else if(y<-1){
    printf("no");
}
else
printf("yes");
return 0;
}