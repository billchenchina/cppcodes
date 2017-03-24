#include<iostream>
#include<cstdio>
using namespace std;
int pd(int);
int main() {
    int n,all=0,a;
    cin>>n;
    for(int i=1; i<=n; i++) {
        a=pd(i);
        all+=a*a;
    }
    cout<<all;
    return 0;
}
int pd(int i) {
    if(i%7==0){
        return 0;
    }
    else if(i%10==7||i/10==7){
        return 0;
    }
    else
    return i;
}