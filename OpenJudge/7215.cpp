#include <cstdio>
#include <iostream>
using namespace std;
int dg(int,int);
int main(){
    int a;
    while(cin>>a){
        cout<<dg(a,a)<<endl;
    }
    return 0;
}
int dg(int sum,int pre){
    if(sum==1)return 1;
    if(sum==0)return 1;
    int ttl=0;
    for(int i=int(pre>sum?sum:pre);i>=1;i--){
        ttl+=dg(sum-i,i);
    }
    return ttl;
}