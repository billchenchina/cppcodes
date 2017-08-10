#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int r,c;
int fx[4]={1,0,-1,0},fy[4]={0,1,0,-1};
struct node{
    int x;
    int y;
    int step;
    /*
        color
        0:can_be_used
        1:cant_be_used or already_used
    */
    int color;
    node(int xx,int yy,int num){
        this->x=xx;
        this->y=yy;
        this->color=num;
        step=0;
    }
    node(){}
};
node nodes[42][42];
node que[2000];
int quetail,quehead;
void srch();
void addToQue(node TO);
int main() {
    cin>>r>>c;
    for(int i=0;i<r;i++){
        char str[42];
        cin.getline(str,41);
        for(int j=0;j<c;j++){
            nodes[i][j]=node(j,i,(str[j]=='.'?0:1));
        }
    }
    nodes[0][0].color=1;
    addToQue(nodes[0][0]);
    srch();
    return 0;
}
void addToQue(node TO){
    que[quetail++]=TO;
}
void srch(){
    while(quehead<quetail){
        if(que[quehead].x==c&&que[quetail].y==r){

        }
    }
}
