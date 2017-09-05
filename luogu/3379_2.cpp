#include <bits/stdc++.h>
using namespace std;

#define maxn 1000001


int N,M,root;
vector<int>mapn[maxn];

vector<int>dfs_list;

int dfn[maxn];
bool vis[maxn];
int first_pos[maxn];
int defaultdfn=1;
int _M[maxn][21];
int another_dfn[maxn];
void process();
void process2();
int getmin(int a,int b);
void connect();
void dfs(int i);

int read()
{
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}


int main()
{
    N=read();M=read();root=read();
    //cin>>N>>M>>root;
    for(int i=0; i<N-1; ++i)
    {
        connect();
    }
    dfs(root);

    process();
    for(int i=0; i<M; ++i)
    {
        process2();
    }
}



void connect()
{
    int x,y;
    x=read();y=read();
    //cin>>x>>y;
    mapn[x].push_back(y);
    mapn[y].push_back(x);
}



void dfs(int i)
{
    vis[i]=1;
    int vsize=mapn[i].size();
    dfn[i]=defaultdfn++;
    another_dfn[dfn[i]]=i;
    dfs_list.push_back(dfn[i]);
    first_pos[dfn[i]]=dfs_list.size()-1;
    for(int j=0; j<vsize; ++j)
    {
        int nextp=mapn[i][j];
        if(!vis[nextp])
        {
            dfs(nextp);
            dfs_list.push_back(dfn[i]);
        }
    }
}

void process2()
{
    int x,y;
    x=read();y=read();
    //cin>>x>>y;
    x=dfn[x];
    y=dfn[y];
    if(x>y)
    {
        swap(x,y);
    }
    x=first_pos[x];y=first_pos[y];
    printf("%d\n",another_dfn[getmin(x,y)]);
    //cout<<another_dfn[getmin(x,y)]<<endl;
}

int getmin(int a,int b)
{
    int k=log2(b-a+1);
    if((b-a+1)&(b-a))
    {
        int min1=dfs_list[_M[a][k]];
        int min2=dfs_list[_M[b-(1<<(k))][k]];
        return min1<min2?min1:min2;
    }
    else
    {
        return dfs_list[_M[a][k]];
    }
}

void process() {
    vector<int>&A=dfs_list;
    int N=A.size();
    int i, j;
    for (i = 0; i < N; i++)
        _M[i][0] = i;
    for (j = 1; 1 << j <= N; j++)
        for (i = 0; i + (1 << j) - 1 < N; i++)
            if (A[_M[i][j - 1]] < A[_M[i + (1 << (j - 1))][j - 1]])
                _M[i][j] = _M[i][j - 1];
            else
                _M[i][j] = _M[i + (1 << (j - 1))][j - 1];
}
