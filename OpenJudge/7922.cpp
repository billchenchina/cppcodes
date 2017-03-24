#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int cj(int a){
    for(int i=2;i<=sqrt(a);i++){
        if(a%i==0){
            return i;
        }
    }
}
int main() {
int n,p;
cin>>n;
p=n/cj(n);
cout<<p;
    return 0;
}