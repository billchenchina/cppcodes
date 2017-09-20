#include <bits/stdc++.h>

using namespace std;

struct edge
{
    int next;
    int to;
};

edge edges[30001];
int first_l[30001];
int weight[30001];
void add_edge(int u,int v,int i)
{
    edges[i].next=first_l[u];
    edges[i].to=v;
    first_l[u]=i;
}


int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n-1;++i)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add_edge(u,v,i);
    }
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&weight[i]);
    }
    int Q;
    scanf("%d",&Q);
    while(Q--)
    {
        char index[10];
        scanf("%s",index);
        if(strcmp(index,"QMAX")==0)
        {
            int u,v;
            scanf("%d%d",&u,&v);
        }
        else if(strcmp(index,"CHANGE")==0)
        {
            int u,v;
            scanf("%d%d",&u,&v);
        }
        else if(strcmp(index,"QSUM")==0)
        {
            int u,v;
            scanf("%d%d",&u,&v);
        }
    }
}