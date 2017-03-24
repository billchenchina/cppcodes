#include<cstdio>
#include<iostream>
using namespace std;

int main() {
int a,b,c;
char d;
scanf("%d %c",&a,&d);
if(a<=1000){
    c=8;
}
else{
b=a-1000;
    if(b%500==0){
        c=8+4*b/500;
    }
    else
        c=12+b/500*4;

}
if(d=='y')
c=c+5;
printf("%d",c); 
return 0;
}