#include<cstdio>
#include<iostream>
using namespace std;
int main(){
int m,n,m1,n1,gs,rslt;
cin>>m>>n;
if(m%2==0   &&  n%2==0){
    m1=m+1;
    n1=n-1;
    gs=(n1-m1)/2+1;
    rslt=(m1+n1)*gs/2;
}
else if(m%2==0){
    m1=m+1;
    gs=(n-m1)/2+1;
    rslt=(m1+n)*gs/2;
}
else if(n%2==0){
    n1=n-1;
    gs=1+(n1-m)/2;
    rslt=(m+n1)*gs/2;   
}
else{
    gs=(n-m)/2+1;
    rslt=(m+n)*gs/2;    
}
cout<<rslt;
return 0;
}