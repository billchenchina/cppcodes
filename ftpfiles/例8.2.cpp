#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int ttl=0;
int m,n;
int fx[4]= {0,1,0,-1},fy[4]= {1,0,-1,0};
struct node {
    int x;
    int y;
    short num;
    int xbnum;
};
node mapn[300][300];
queue <node> q;
void bfs(int,int);
int main() {
    cin>>m>>n;
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            int tmp;
            scanf("%1d",&tmp);
            mapn[i][j].num=tmp>0?1:0;
            mapn[i][j].x=j;
            mapn[i][j].y=i;
        }
    }
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            if(mapn[i][j].num==1) {
                bfs(j,i);
            }
        }
    }
    cout<<ttl;
    return 0;
}
void bfs(int x,int y) {
    ttl++;

    mapn[y][x].xbnum=ttl;
    mapn[y][x].num=-1;
    q.push(mapn[y][x]);
    while(!q.empty()) {
        for(int i=0; i<4; i++) {
            int xx=q.front().x+fx[i],yy=q.front().y+fy[i];
            if(xx>=1&&xx<=n&&yy>=1&&yy<=m) {
                if(mapn[yy][xx].num==1) {
                    mapn[yy][xx].num=-1;
                    q.push(mapn[yy][xx]);
                }
            }
        }
        q.pop();
    }

}
//0为无细胞
//1为有细胞且未访问过
//-1为有细胞且访问过
