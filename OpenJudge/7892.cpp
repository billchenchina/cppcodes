#include<iostream>
#include<cstdio>
using namespace std;

int main() {
    int k,i=2;
    double sn=1.0;
    scanf("%d",&k);
    while(sn<k) {
        sn=sn+1.0/i;
        i++;
    }
    if(k==1)
        printf("%d",i);
    else {
        i--;
        printf("%d",i);
    }

    return 0;
}