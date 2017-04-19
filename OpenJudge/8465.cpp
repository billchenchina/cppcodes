#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

bool visited[15][15];
int n,m;
int maxnum;
int tries;
void searchmap(int x,int y);
const int directions[8][2]= {1,2 , 2,1 , 2,-1 , 1,-2 ,
                             -1,-2 , -2,-1 , -2,1 , -1,2
                            };
bool allvisited();

int main() {
    int T;
    cin>>T;
    while(T--) {
        memset(visited,0,sizeof(visited));
        int x,y;
        cin>>n>>m>>x>>y;
        tries=0;
        visited[x][y]=1;
        searchmap(x,y);
        cout<<tries<<endl;
    }
    return 0;
}
bool allvisited(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(visited[i][j]==0)return false;
        }
    }
    return true;
}
void searchmap(int x,int y){
    if(allvisited()){tries++;return;}
    for(int i=0;i<8;i++){
        int xx=x+directions[i][0],yy=y+directions[i][1];
        if(xx>=n||xx<0||yy>=m||yy<0)continue;
        else{
            if(!visited[xx][yy]){
                visited[xx][yy]=1;
                searchmap(xx,yy);
                visited[xx][yy]=0;
            }
        }
    }
}
