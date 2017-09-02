#include <cstdio>
#include <iostream>
#include <memory.h>
using namespace std;
int mapn[10001][10001];
int main() {

    memset(mapn,0,sizeof(mapn));
    int n;
    cin>>n;
    int x;
    for(int i=1;i<=n;i++){
        int tmp;
        scanf("%d",&tmp);
        x=tmp;
        mapn[i][1]=1;
        for(int j=1;j<=tmp;j++){
            mapn[i][j]=max(mapn[i][j-1],mapn[i-1][j]+j);
        }
    }
    cout<<mapn[n][x];
    return 0;
}
