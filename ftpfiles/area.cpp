#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int fx[4]= {0,1,0,-1},fy[4]= {1,0,-1,0};
int ttl;
struct node {
    int x;
    int y;
    int value;
    int visited;
};
node ndmap[100][100];

int n,m;
void bfs(int,int);
int main()
 {
    int ttl2=0;
    cin>>m>>n;
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            cin>>ndmap[i][j].value;
            if(ndmap[i][j].value==1)ttl2++;
        }
    }
    for(int i=1; i<=m; i++) {
        if(ndmap[i][n].value==0&&ndmap[i][n].visited==0) {
            bfs(n,i);
        }
    }
    for(int i=1; i<=m; i++) {
        if(ndmap[i][1].value==0&&ndmap[i][1].visited==0) {
            bfs(1,i);
        }
    }
    for(int i=1; i<=n; i++) {
        if(ndmap[1][i].value==0&&ndmap[1][i].visited==0) {
            bfs(i,1);
        }
    }
    for(int i=1; i<=n; i++) {
        if(ndmap[m][i].value==0&&ndmap[m][i].visited==0) {
            bfs(i,m);
        }
    }


    cout<<int((m*n)-ttl-ttl2);

    return 0;
}
void bfs(int x,int y) {
    queue<node>q;
    ndmap[y][x].visited=1;
    ndmap[y][x].y=y;
    ndmap[y][x].x=x;
    q.push(ndmap[y][x]);
    ttl++;
    while(!q.empty()) {
        for(int i=0; i<4; i++) {
            int xx=q.front().x+fx[i],yy=q.front().y+fy[i];
            if(xx>n||yy>m||xx<1||yy<1)continue;
            else {
                if(ndmap[yy][xx].visited==0&&ndmap[yy][xx].value==0) {
                    ndmap[yy][xx].visited=1;
                    ndmap[yy][xx].y=yy;
                    ndmap[yy][xx].x=xx;
                    q.push(ndmap[yy][xx]);
                    ttl++;
                }
            }
        }
        q.pop();
    }
}
