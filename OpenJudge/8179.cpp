#include<iostream>
#include<cstdio>
using namespace std;

int main() {
    int m,n,m1,n1,rslt,a;
    cin>>m>>n;
    if(m%17==0  &&  n%17==0){
        a=1+(n-m)/17;
        rslt=(m+n)*a/2;
    }
    else if(m%17==0){
        n1=n/17;
        n=n1*17;
        a=1+(n-m)/17;
        rslt=(m+n)*a/2;
    }
    else if(n%17==0){
        m1=1+m/17;
        m=m1*17;
        a=1+(n-m)/17;
        rslt=(m+n)*a/2;
    }
    else{
        m1=1+m/17;
        m=m1*17;        
        n1=n/17;
        n=n1*17;
        a=1+(n-m)/17;
        rslt=(m+n)*a/2;     
    }
    cout<<rslt;
    return 0;
}