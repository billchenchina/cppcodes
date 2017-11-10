#include <bits/stdc++.h>
using namespace std;

namespace BCJ
{

const int MAXN=10000+1;

int fa[MAXN];


int find_ancestor(int x)
{
    if(x==fa[x])
    {
        return x;
    }
    else
    {
        fa[x]=find_ancestor(fa[x]);
    }
    return fa[x];
}

void my_merge(int x,int y)
{
    find_ancestor(x);
    find_ancestor(y);
    if(fa[x]!=fa[y])
    {
        fa[fa[x]]=fa[y];
    }
}


void my_query(int x,int y)
{
    find_ancestor(x);
    find_ancestor(y);
    if(fa[x]==fa[y])
    {
        cout<<"Y"<<endl;
    }
    else

    {
        cout<<"N"<<endl;
    }
}

void init()
{
    for(int i=1;i<=MAXN;++i)
    {
        fa[i]=i;
    }
}


}

using namespace BCJ;

int main()
{
    int N,M;
    cin>>N>>M;
    init();
    for(int i=1;i<=M;++i)
    {
        int opt,x,y;
        cin>>opt>>x>>y;
        if(opt==1)
        {
            my_merge(x,y);
        }
        if(opt==2)
        {
            my_query(x,y);
        }
    }
}


