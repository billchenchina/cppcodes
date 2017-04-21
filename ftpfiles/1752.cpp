#include <cstdio>
#include <iostream>
using namespace std;
int main(){
    int a,minn,maxn;
    cin>>a;
    if(a%2==1){
        cout<<0<<" "<<0;
        return 0;
    }
    if(a%4==0)minn=a/4;
    else minn=1+a/4;
    maxn=a/2;
    cout<<minn<<' '<<maxn;
	return 0;
}
