#include <cstdio>
#include <iostream>
using namespace std;
int a[1000];
int f(int k){
    if(a[k]!=0) return a[k];
    if(k==1){
        return 1;
    }
    if(k==2){
        return 2;
    }
    a[k]=f(k-1)+f(k-2);
    return a[k] ;
}




int main() {
int k;
while(cin>>k)
cout<<f(k)<<endl;
    return 0;
}
