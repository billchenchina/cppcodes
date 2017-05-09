#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int pd(int a,int b);
int main() {
int a,b,c,max=-65534;
cin>>a>>b>>c;
max=pd(a,b);
max=pd(max,c);
cout<<max;
    return 0;
}
int pd(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
