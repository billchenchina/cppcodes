#include <bits/stdc++.h>

using namespace std;

int mapn[1001][1001];


int main()
{
    ios::sync_with_stdio(false);
    int N,M,S,T;
    cin>>N>>M>>S>>T;
    int S_arr[1001];
    vector<bool>visited(N+1,0);
    for(int i=0; i<=N; ++i)
    {
        S_arr[i]=214748364;
        for(int j=0; j<=N; ++j)
        {
            if(i!=j)
                mapn[i][j]=214748364;
            else
                mapn[i][j]=0;
        }
    }
    S_arr[S]=0;
    for(int i=0; i<M; ++i)
    {
        int u,v,l;
        cin>>u>>v>>l;
        if(l<mapn[u][v])
        {
            mapn[u][v]=mapn[v][u]=l;
            if(u==S)
            {
                S_arr[v]=l;
            }
            if(v==S)
            {
                S_arr[u]=l;
            }
        }
    }
#define vis visited
    for(;;)
    {
        int id=0;
        int minn=214748364;
        for(int i=1; i<=N; ++i)
        {
            if(vis[i]==false&&S_arr[i]<minn)
            {
                id=i;
                minn=S_arr[i];
            }
        }
        if(id==T||id==0)
        {
            break;
        }
        vis[id]=true;
        for(int i=1; i<=N; ++i)
        {
            if(vis[i]==false&&S_arr[i]>S_arr[id]+mapn[id][i])
            {
                S_arr[i]=S_arr[id]+mapn[id][i];
            }
        }
    }
    cout<<S_arr[T];

    return 0;

}
