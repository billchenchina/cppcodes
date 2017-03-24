#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int k[101];
int main() {
int n,r=0,m;
cin>>n;
for(int i=0;i<n;i++){
    cin>>k[i];
}
cin>>m;
for(int i=0;i<n;i++){
    if(k[i]==m){
        r++;
    }
}
cout<<r;
    return 0;
}
