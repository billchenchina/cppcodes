#include <cstdio>
#include <iostream>
using namespace std;
bool flag;
int n,m;
bool check(int x,int y);
void bfs();
void print(int q);
int fx[4]= {0,1,0,-1},fy[4]= {1,0,-1,0};
int startx,starty,stopx,stopy;
class node {
public:
    int x;
    int y;
    int step;
    int pre;
    int value;
    node() {
        value=-1;
    }
};
node mapn[50][50];
node que[2600];
int head,tail;

int main() {
    cout<<"输入n行m列"<<endl;
    cin>>n>>m;
    cout<<"输入地图"<<endl;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin>>mapn[i][j].value;
            mapn[i][j].x=i;
            mapn[i][j].y=j;
        }
    }
    cout<<"入口："<<endl;
    cin>>startx>>starty;
    cout<<"出口："<<endl;
    cin>>stopx>>stopy;
    head=0;
    tail=1;
    que[tail]=mapn[startx][starty];

    bfs();

    if(flag==0)cout<<"404 Not Found";
    return 0;
}
void bfs() {
    while(head<tail) {
        head++;
        if(que[head].x==stopx&&que[head].y==stopy) {
            print(head);
            cout<<endl;
            flag=1;
            break;
        }

        for(int i=0; i<4; i++) {
            int xx=que[head].x+fx[i],yy=que[head].y+fy[i];
            if(check(xx,yy)) {
                tail++;
                que[tail]=mapn[xx][yy];
                que[tail].pre=head;
                mapn[xx][yy].value=-1;
                que[tail].step=que[head].step+1;
            }
        }

    }

}
bool check(int x,int y) {
    if(x>=1&&x<=n&&y>=1&&y<=m&&mapn[x][y].value==0) {
        return 1;
    }
    return 0;
}
void print(int q) {
    if(q!=1){
        print(que[q].pre);
        cout<<"("<<que[q].x<<","<<que[q].y<<")";
        if(q!=tail){
            cout<<"->";
        }
    }else{
        cout<<"("<<que[q].x<<","<<que[q].y<<")->";
    }

}
