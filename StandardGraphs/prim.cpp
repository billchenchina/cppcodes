#include <cstdio>
#include <iostream>
#include <memory.h>
#include <climits>
using namespace std;
#define graph_length 500
#define gl graph_length
#define g graph
int graph[gl][gl];
int minn[gl];
bool visited[gl];
int shortest;
int n;
int main() {
    cin>>n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin>>g[i][j];
        }
    }
    memset(minn,0x3f,sizeof(minn));
    minn[1]=0;
    for(int i=1; i<=n; i++) {
        int u=0;
        int mint=INT_MAX;

        for(int j=1; j<=n; j++) {
            if(minn[j]<mint&&visited[j]!=true) {
                mint=minn[j];
                u=j;
            }
        }

        visited[u]=true;
        shortest+=mint;
        for(int j=1; j<=n; j++) {
            if(visited[j]!=true&&minn[j]>g[u][j]) {
                minn[j]=graph[u][j];
            }
        }
    }
    cout<<shortest;
    return 0;
}
