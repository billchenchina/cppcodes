#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int fx[8]= {1,2,2,1,-1,-2,-2,-1},
           fy[8]= {2,1,-1,-2,-2,-1,1,2};
int mapn[15][15];
int n,m;
int ttl;
void searchmap(int x,int y);

int main() {
    int T;
    cin>>T;
    while(T--) {
        memset(mapn,0,sizeof(mapn));
        int x,y;
        ttl=1;
        cin>>n>>m>>x>>y;
        mapn[x][y]=1;
        searchmap(x,y);
    }
    return 0;
}

void searchmap(int x,int y){

}
