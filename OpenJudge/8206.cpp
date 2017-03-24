#include <cstdio>
#include <iostream>
using namespace std;
double l,r,mid;
double f(double x) {
    return x*x*x*x*x-15.0*x*x*x*x+85.0*x*x*x-225.0*x*x+274.0*x-121.0;
}
double bs();
int main() {
    l=1.5,r=2.4;
    printf("%.6lf",bs());
    return 0;
}

double bs() {
    while(l<=r&&r-l>=0.0000001) {
        mid=(l+r)/2;
        if(f(mid)==0) {
            return mid;
        } else if(f(mid)>0) {
            l=mid;
        }else{
            r=mid;
        }
    }
    return mid;
    
}