#include <iostream>
#include <queue>
using namespace std;
int H,W,D,R;

struct node
{
    int ln;
    int col;
    bool usedMagic;
    int minnRoute;
    // if status = 0
    //   not vis
    // if status = 1
    //   visited
    // if status = -1
    //   cannot be visited
    short status;
    bool inQue;
};
int directionsy[4]= {1,0,-1,0};
int directionsx[4]= {0,1,0,-1};
node mapn[1001][1001];
queue<node>q;
inline void go()
{
    while(!q.empty())
    {
        int y=q.front().ln,int x=q.front().col;

        for(int i=0; i<4; i++)
        {
            int tmpy=y+directionsy[i],tmpx=x+directionsx[i];
            if(tmpy>0&&tmpy<=H&&tmpx>0&&tmpx<=W)
            {
                node &tmpnode=mapn[tmpy][tmpx];
                if(tmpnode.inQue==false&&tmpnode.status==0)
                {

                }
            }

        }
    }

}
int main()
{

    cin>>H>>W>>D>>R;
    cin.get();
    for(int i=1; i<=H; i++)
    {
        for(int j=1; j<=W; j++)
        {
            mapn[i][j].ln=i;
            mapn[i][j].col=j;
            mapn[i][j].usedMagic=false;
            mapn[i][j].inQue=false;
            mapn[i][j].minnRoute=1000000001;
            char tmpchar=cin.get();
            if(tmpchar=='.')
            {
                mapn[i][j].status=0;
            }
            else if(tmpchar=='#')
            {
                mapn[i][j].status=-1;
            }
        }
        cin.get();
    }
    mapn[1][1].minnRoute=0;
    q.push(mapn[1][1]);
    go(1,1);

    return 0;
}
