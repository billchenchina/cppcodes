#include <bits/stdc++.h>

using namespace std;

int N,M,R,P;

struct Edge
{
    int to;
    int next;
};

int val[10001];

Edge edges[20002];

int firstpos[10001];

int cnt=0;

void connect(int x,int y)
{
    edges[cnt].to=y;
    edges[cnt].next=firstpos[x];
    firstpos[x]=cnt;
    cnt++;
    edges[cnt].to=x;
    edges[cnt].next=firstpos[y];
    firstpos[y]=cnt;
    cnt++;
}

void buildtree()
{
    
}


int main()
{
    cin>>N>>M>>R>>P;
    for(int i=1; i<=N; ++i)
    {
        cin>>val[i];
        val[i]%=P;
    }
    for(int i=1; i<=N-1; ++i)
    {
        int x,y;
        cin>>x>>y;
        connect(x,y);
    }
    buildtree();
    for(int i=1; i<=M; ++i)
    {
        int opt;
        cin>>opt;
        switch(opt)
        {
        case 1:
        {
            int x,y,z;
            cin>>x>>y>>z;

            break;
        }
        case 2:
        {
            int x,y;
            cin>>x>>y;
            break;
        }
        case 3:
        {
            int x,y;
            cin>>x>>y;
            break;
        }
        case 4:
        {
            int x;
            cin>>x;
            break;
        }
        }
    }
}
