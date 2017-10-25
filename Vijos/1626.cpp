#include <bits/stdc++.h>

using namespace std;
vector<vector<int> >connections;
vector<vector<int> >connections_after_suo;
vector<vector<int> >suodians;
vector<bool>is_suo;
stack<int>s;

vector<vector<int> >pairs;

int *fa;
int time_stamp=1;
int *mapn;

bool *inStack;

int *dfn;
int *low;

int *times;

int *size;

int ans=0;

void dfs(int u)
{
    dfn[u]=low[u]=time_stamp;
    time_stamp++;
    s.push(u);
    inStack[u]=true;
    for(size_t i=0; i<connections[u].size(); ++i)
    {
        int v=connections[u][i];
        if(dfn[v]==0)
        {
            dfs(v);
            low[u]=min(low[u],low[v]);
        }
        else if(inStack[v])
        {
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(dfn[u]==low[u])
    {
        bool is_good=false;
        for(;;)
        {
            int v=s.top();
            s.pop();
            size[u]++;
            suodians[u].push_back(v);
            inStack[v]=false;
            mapn[v]=u;
            if(u!=v)
            {
                is_good=true;
                fa[v]=u;
            }
            else if(u==v)
            {
                if(is_good)
                {
                    ans++;
                }
                break;
            }
        }
    }
}


void rebuild(int N)
{
    for(int i=1; i<=N; ++i)
    {
        int suo=mapn[i];
        is_suo[suo]=true;
        for(size_t j=0; j<connections[i].size(); ++j)
        {
            if(mapn[connections[i][j]]!=suo)
            {
                connections_after_suo[suo].push_back(mapn[connections[i][j]]);
            }
        }
    }
}

int main()
{
    int N,M;
    cin>>N>>M;
    // alloc
    dfn=new int[N+1];
    low=new int[N+1];
    inStack=new bool[N+1];
    mapn=new int[N+1];
    size=new int[N+1];
    times=new int[N+1];
    fill(inStack+1,inStack+N+1,false);
    memset(dfn,0,(N+1)*sizeof(int));
    memset(low,0,(N+1)*sizeof(int));
    memset(size,0,(N+1)*sizeof(int));
    fa=new int[N+1];

    //init
    for(int i=1; i<=N; ++i)
    {
        fa[i]=i;
    }
    connections.resize(N+1);
    connections_after_suo.resize(N+1);
    is_suo.resize(N+1);
    suodians.resize(N+1);
    for(int i=1; i<=M; ++i)
    {
        int A,B;
        cin>>A>>B;
        connections[A].push_back(B);
    }
    for(int i=1; i<=N; ++i)
    {
        if(dfn[i]==0)
        {
            dfs(i);
        }
    }
    cout<<ans<<endl;
    rebuild(N);
    vector<vector<int> >ans_arr;
    for(int i=1; i<=N; ++i)
    {
        if(connections_after_suo[i].size()==0&&is_suo[i])
        {
            sort(suodians[i].begin(),suodians[i].end());
            ans_arr.push_back(vector<int>(suodians[i].begin(),suodians[i].end()));
        }
    }
    if(ans_arr.size()!=1||ans_arr[0].size()==1)
    {
        cout<<-1;
    }
    else
    {
        for(size_t i=0;i<ans_arr[0].size();++i)
        {
            cout<<ans_arr[0][i]<<' ';
        }
    }
    connections.clear();
    connections_after_suo.clear();
    suodians.clear();
    is_suo.clear();
    while(!s.empty())s.pop();

    pairs.clear();

    delete fa;
    delete mapn;

    delete inStack;

    delete dfn;
    delete low;

    delete times;

    delete size;
}
