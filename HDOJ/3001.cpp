
#include <bits/stdc++.h>

using namespace std;

int pow3[11];
int inch3[60000][11];
int dp_map[60000][11];
int mapn[11][11];
int n,m;

void init()
{
    pow3[0]=1;
    for(int i=1;i<11;++i)
    {
        pow3[i]=pow3[i-1]*3;
    }
    for(int i=0;i<pow3[10];++i)
    {
        int k=i;
        int pos=0;
        while(k)
        {
            inch3[i][pos]=k%3;
            k/=3;
            pos++;
        }
    }
}

int main()
{
    init();
    while(cin>>n>>m)
    {
        int minn=INT_MAX;
        for(int i=0;i<11;++i)
        {
            fill(mapn[i],mapn[i]+11,INT_MAX);
        }
        for(int i=0;i<m;++i)
        {
            int x,y,z;
            cin>>x>>y>>z;
            x--;y--;
            mapn[x][y]=mapn[y][x]=min(mapn[y][x],z);
        }
        for(int i=0;i<pow3[n];++i)
        {
            bool have_not_visited=0;
            for(int k=0;k<n;++k)
            {
                if(inch3[i][k]==0)
                {
                    have_not_visited=1;
                }
                if(inch3[i][k]<2)
                {
                    dp[]
                }
            }

            if(!have_not_visited)
            {
                for(int j=0;j<n;++j)
                {
                    minn=(minn>dp_map[i][j]?dp_map[i][j]:minn);
                }
            }
        }
    }
}
