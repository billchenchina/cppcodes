#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>

#define MAXN int(50050)

using namespace std;
int height[MAXN];
int Map[MAXN][25];
int Map2[MAXN][25];
int N,Q;

void preprogress();

void progress();

int read()
{
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}

int main()
{
    N=read();
    Q=read();

    for(int i=0;i<N;++i)
    {
        height[i]=read();
    }
    preprogress();
    for(int i=0;i<Q;++i)
    {
        progress();
    }

}

void preprogress()
{
    for(int i=0,j=0;i<N;++i)
    {
        Map[i][j]=height[i];
        Map2[i][j]=height[i];
    }
    for(int j=1;(1<<j)<=N;++j)
    {
        for(int i=0;(i+(1<<j)-1)<N;++i)
        {
            Map[i][j]=max(Map[i][j-1],Map[i+(1<<j-1)][j-1]);
            Map2[i][j]=min(Map2[i][j-1],Map2[i+(1<<j-1)][j-1]);
        }
    }
}

void progress()
{
    int f,t;
    f=read();
    t=read();
    int len=t-f+1;
    f--;
    t--;
    len=log(1.0*len)/log(2.0);

    int maxn=max(Map[f][len],Map[t-(1<<len)+1][len]);
    int minn=min(Map2[f][len],Map2[t-(1<<len)+1][len]);
    printf("%d\n",maxn-minn);

}
