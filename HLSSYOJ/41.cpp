#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    int to;
    int next;
};

Edge edge_list[2000011];
int edge_list_=1;

int first[1000001];

inline void addedge_(int u,int v)
{
    edge_list[edge_list_].to=v;
    edge_list[edge_list_].next=first[u];
    first[u]=edge_list_;
    edge_list_++;
}

inline void addedge(int u,int v)
{
    addedge_(u,v);
    addedge_(v,u);
}

bool visited[1000001];

void dfs(int u)
{
    visited[u]=true;
    for(int i=first[u]; i; i=edge_list[i].next)
    {
        if(!visited[edge_list[i].to])
        {
            dfs(edge_list[i].to);
        }
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; ++i)
    {
        int to;
        cin>>to;
        addedge(i,to);
    }
    int ans=0;
    for(int i=1; i<=n; ++i)
    {
        if(!visited[i])
        {
            dfs(i);
            ans++;

        }
    }
    cout<<ans;

}
