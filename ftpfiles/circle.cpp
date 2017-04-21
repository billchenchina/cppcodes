#include <cstdio>
#include <iostream>
#include <memory.h>
#include <climits>
using namespace std;
#define g graph
int graph[1000][1000],dis[1000][1000];
int n,m;
int main() {
    //#define HAVEDIRCTION
    int shortest=INT_MAX;
    memset(g,1,sizeof(g));
    memset(dis,1,sizeof(dis));
    cin>>n>>m;
    for(int i=0; i<m; i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        scanf("%d",&g[a][b]);
        dis[a][b]=g[a][b];
#ifndef HAVEDIRCTION
        graph[b][a]=graph[a][b];
        dis[b][a]=g[a][b];
#endif // HAVEDIRCTION
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<i; j++) {
            for(int k=1; k<i; k++) {
                if(i!=j && i!=k && j!=k)
                    shortest=min(shortest,dis[j][k]+g[k][i]+g[i][j]);
            }
        }
        for(int j=1; j<=n; j++) {
            for(int k=1; k<=n; k++) {
                dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
#ifndef HAVEDIRCTION
                dis[k][j]=dis[j][k];
#endif // HAVEDIRCTION
            }
        }
    }
    cout<<shortest;
    return 0;
}
