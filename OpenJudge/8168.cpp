#include<iostream>
#include<cstdio>
using namespace std;

int main() {
long long a,n,r;
cin>>a>>n;
r=1;
for(int i=1;i<=n;i++){
    r=r*a;
}
cout<<r;
return 0;
}