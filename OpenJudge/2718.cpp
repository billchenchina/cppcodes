#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define maxn 20
int  a[maxn][maxn];

int main(){
    for(int y=1;y<maxn;y++){
        for(int x=1;x<=y;x++){
            if(x==1||x==y)a[x][y]=1;
            else{
                a[x][y]=a[x-1][y-1]+a[x][y-1];
            }
        }
    }
    int m,n,ttl,tmp;
    cin>>m>>n;
    ttl=m+n-1;
    tmp=abs(m-n);
    cout<<a[(ttl+2)/2+tmp/2][ttl];
    return 0;
}