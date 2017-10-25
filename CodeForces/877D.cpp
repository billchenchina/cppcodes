#include <bits/stdc++.h>

using namespace std;
char mapn[1001][1001];
bool vis[1001][1001];
string tmp;
struct pint
{
    int x;
    int y;
    int depth;
    pint(int _x,int _y,int _dep):x(_x),y(_y),depth(_dep) {}
};

int dir[4][2]= {1,0,0,1,-1,0,0,-1};
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    getline(cin,tmp);
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<m; ++j)
        {
            mapn[i][j]=getchar();
        }
        getline(cin,tmp);
    }
    int x1,y1,x2,y2;
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    x1--;
    y1--;
    x2--;
    y2--;
    queue<pint>q;
    if(x1==x2&&y1==y2)
    {
        cout<<0;
        return 0;
    }
    q.push(pint(x1,y1,0));
    vis[x1][y1]=true;
    while(!q.empty())
    {
        pint p=q.front();
        q.pop();
        bool flag1=true,flag2=true,flag3=true,flag4=true;
        for(int i=1; i<=k; ++i)
        {

            if(flag1&&p.x+i>=0&&p.x+i<n&&(!vis[p.x+i][p.y])&&mapn[p.x+i][p.y]=='.')
            {
                vis[p.x+i][p.y]=true;
                q.push(pint(p.x+i,p.y,p.depth+1));
                if(p.x+i==x2&&p.y==y2)
                {
                    cout<<p.depth+1;
                    return 0;
                }
            }
            if(p.x+i>=0&&p.x+i<n&&mapn[p.x+i][p.y]!='.')
            {
                flag1=false;
            }
            if(flag2&&p.x-i>=0&&p.x-i<n&&(!vis[p.x-i][p.y])&&mapn[p.x-i][p.y]=='.')
            {
                vis[p.x-i][p.y]=true;
                q.push(pint(p.x-i,p.y,p.depth+1));
                if(p.x-i==x2&&p.y==y2)
                {
                    cout<<p.depth+1;
                    return 0;
                }
            }
            if(p.x-i>=0&&p.x-i<n&&mapn[p.x-i][p.y]!='.')
            {
                flag2=false;
            }
            if(flag3&&p.y+i>=0&&p.y+i<m&&(!vis[p.x][p.y+i])&&mapn[p.x][p.y+i]=='.')
            {
                vis[p.x][p.y+i]=true;
                q.push(pint(p.x,p.y+i,p.depth+1));
                if(p.x==x2&&p.y+i==y2)
                {
                    cout<<p.depth+1;
                    return 0;
                }
            }
            if(p.y+i>=0&&p.y+i<m&&mapn[p.x][p.y+i]!='.')
            {
                flag3=false;
            }
            if(flag4&&p.y-i>=0&&p.y-i<m&&(!vis[p.x][p.y-i])&&mapn[p.x][p.y-i]=='.')
            {
                vis[p.x][p.y-i]=true;
                q.push(pint(p.x,p.y-i,p.depth+1));
                if(p.x==x2&&p.y-i==y2)
                {
                    cout<<p.depth+1;
                    return 0;
                }
            }
            if(p.y-i>=0&&p.y-i<m&&mapn[p.x][p.y-i]!='.')
            {
                flag4=false;
            }
        }
    }
    cout<<-1;

}
