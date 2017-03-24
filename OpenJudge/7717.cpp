#include<cstdio>
#include<iostream>
using namespace std;

int main() {
int a,i;
cin>>a;
i=0;
if(a%3==0)
{
    printf("3 ");
    i++;
}
if(a%5==0){
    printf("5 ");
    i++;
}
if(a%7==0){
    printf("7");
    i++;
}
if(i==0)
printf("n");
    return 0;
}