#include <cstdio>
#include <iostream>
#include <memory.h>
using namespace std;
#define MAX 10007

int main() {
    int n,m;
    int maxn[10003];
    int isbroken[10003];

    while(cin>>n>>m) {
        memset(maxn,0,sizeof(maxn));
        memset(isbroken,0,sizeof(isbroken));
        for(int i=0; i<m; i++) {
            int x;
            cin>>x;
            isbroken[x]=1;
        }
        maxn[1]=1;
        for(int i=2; i<=n; i++) {
            if(isbroken[i])maxn[i]=0;
            else if(i==2) {
                maxn[i]=1;
            } else if(i==3) {
                maxn[i]=maxn[i-1]+maxn[i-2];
            } else {
                maxn[i]=(maxn[i-1]+maxn[i-2]+maxn[i-3])%MAX;
            }
        }
        cout<<maxn[n]<<endl;
    }
    return 0;
}
