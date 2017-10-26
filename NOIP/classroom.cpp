#include <bits/stdc++.h>

using namespace std;

struct edge
{
    int to;
    int weight;
};

vector<vector<int> >mapn(300,vector<int>(300,INT_MAX));

int main()
{
    int n,m,v,e;
    cin>>n>>m>>v>>e;
    int c[2000];
    int d[2000];
    double k[2000];
    for(int i=0;i<n;++i)
    {
        cin>>c[i];
    }
    for(int i=0;i<n;++i)
    {
        cin>>d[i];
    }
    for(int i=0;i<n;++i)
    {
        cin>>k[i];
    }
    for(int i=0;i<e;++i)
    {
        int a,b,w;
        cin>>a>>b>>w;
        mapn[a][b]=w;
        mapn[b][a]=w;
    }
    for(int i=0;i<v;++i)
    {
        for(int j=0;j<v;++j)
        {
            for(int k=0;k<v;++k)
            {
                if(mapn[i][j]!=INT_MAX&&mapn[i][k]!=INT_MAX&&mapn[j][k]<mapn[j][i]+mapn[i][k])
                {
                    mapn[j][k]=mapn[k][j]=mapn[j][i]+mapn[i][k];
                }
            }
        }
    }

}
