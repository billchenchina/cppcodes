#include<iostream>
#include<cstdio>
using namespace std;

int main() {
int a1,a2,a3,k;
a1=1;
a2=1;
scanf("%d",&k);
if(k==1)
printf("1");
else if(k==2)
printf("1");
else{
    for(int i=1;i<=k-2;i++){
        a3=a1+a2;
        a1=a2;
        a2=a3;  
}
printf("%d",a3);
}



return 0;
}