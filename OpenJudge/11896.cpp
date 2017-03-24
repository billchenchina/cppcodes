#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int pd(int a);
int main() {
    long long a;
    int b;
    cin>>a;
    b=pd(a);
    if(b==0) {
        printf("yes");
    } else {
        printf("no");
    }
    return 0;
}
int pd(int a) {
    if(a<=1) {
        return 1;
    } else {
        int b=sqrt(a);
        for(int i=2; i<=b; i++) {
            if(a%i==0&&a!=b) {
                return 1;
            }
        }
        return 0;
    }
}
