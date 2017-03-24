#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
#define pointnum 50
int n,//num of point
    m;//num of line
int g[pointnum][pointnum];//g[point][point]
int from,to;
int a[pointnum][pointnum];//a[point][num[a]]
int num[pointnum];
bool vis[pointnum];
queue <int> q;//each num in q is num of point
int main() {
    cin>>n>>m;
    memset(g,0x3f,sizeof(g));
    //g=inf;
    for(int i=0; i<m; i++) {
        int f,t,w;
        cin>>f>>t>>w;
        a[f][num[f]]=t;
        num[f]++;
        g[f][t]=w;
    }
    cin>>from>>to;
    g[from][from]=0;
    vis[from]=1;
    q.push(from);
    while(!q.empty()) {

        for(int i=0; i<num[q.front()]; i++) {//i is counter
            if(g[from][a[q.front()][i]]>g[from][q.front()]+g[q.front()][a[q.front()][i]]) {
                g[from][a[q.front()][i]]=g[from][q.front()]+g[q.front()][a[q.front()][i]];
            }


            if(!vis[a[q.front()][i]]) {
                q.push(a[q.front()][i]);
                vis[a[q.front()][i]]=1;
            }
        }
        vis[q.front()]=0;
        q.pop();
    }
    cout<<g[from][to];
    return 0;
}