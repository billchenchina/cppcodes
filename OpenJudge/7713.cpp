#include<cstdio>
#include<iostream>
using namespace std;

int main() {
int lc,tbx,tqc;
cin>>lc;
tqc=50.0+lc/3.0;
tbx=lc/1.2;
if(tqc<tbx)
printf("Bike");
else if(tqc>tbx)
printf("Walk");
else
printf("All");

    return 0;
}