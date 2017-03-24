#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int pd(int a);
int main() {
int l,r,n=0;
cin>>l>>r;
for(int i=l;i<=r;i++){
n=pd(i)+n;
}
cout<<n;
return 0;
}

int pd(int a){
    int k,r=0;
    k=log10(a)+1;
    for(int i=0;i<k;i++){
        if(a%10==2){
            r++;
        }
        a/=10;
    }
    return r;
}