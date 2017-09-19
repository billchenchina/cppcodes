#include <iostream>
#include <vector>
using namespace std;

vector<int>mapn[100002];
bool vis[100002];
bool which_group[100002];
int zero_group_size=0;
int one_group_size=0;

void dfs(int u)
{
    vis[u]=1;
    if(!which_group[u])
    {
        zero_group_size++;
    }
    else
    {
        one_group_size++;
    }
    for(int i=0;i<mapn[u].size();++i)
    {
        int v=mapn[u][i];
        if(!vis[v])
        {
            which_group[v]=!which_group[u];
            vis[v]=true;
            dfs(v);
        }
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n-1;++i)
    {
        int x,y;
        cin>>x>>y;
        mapn[x].push_back(y);
        mapn[y].push_back(x);
    }
    dfs(1);
    long long ans=0;
    for(int i=1;i<=n;++i)
    {
        if(!which_group[i]) // zero group
        {

            ans+=(one_group_size-mapn[i].size());
        }
        else
        {
            ans+=(zero_group_size-mapn[i].size());
        }
    }
    cout<<ans/2;
}
