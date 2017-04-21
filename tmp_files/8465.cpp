#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

int fx[8][2]={2,1,1,2,-1,2,-2,1,-2,-1,-1,-2,1,-2,2,-1};
int n,m;
int steppednum;
int mapsize;
int methods;
inline void init(int y,int x);
void dosearch(int y,int x);
vector<vector<bool> >mapn(11,vector<bool>(11));

int main(){
    int T;
    cin>>T;
    while(T--){
        int x,y;
        cin>>n>>m>>x>>y;
        init(y,x);
        dosearch(y,x);
        cout<<methods<<endl;
    }
    return 0;
}

inline void init(int y,int x){
    fill(mapn.begin(),mapn.end(),vector<bool>(11,0));
    mapn[y][x]=1;
    mapsize=n*m;
    steppednum=1;
    methods=0;
}

void dosearch(int y,int x){
    for(int i=0;i<8;i++){
        int yy,xx;
        yy=y+fx[i][0],xx=x+fx[i][1];
        if(yy>=m||yy<0||xx>=n||xx<0){continue;}
        else{
            if(mapn[yy][xx]==1)continue;
            else{
                mapn[yy][xx]=1;
                steppednum++;
                if(steppednum!=mapsize)dosearch(yy,xx);
                else methods++;
                steppednum--;
                mapn[yy][xx]=0;
            }
        }
    }
}
