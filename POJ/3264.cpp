#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>

#define MAXN int(50050)

using namespace std;
long long height[MAXN];
long long Map[MAXN][25];
long long Map2[MAXN][25];
long long N,Q;

void preprogress();

void progress();



int main()
{

    scanf("%lld%lld",&N,&Q);

    for(long long i=0;i<N;++i)
    {
        scanf("%lld",&height[i]);
    }
    preprogress();
    for(long long i=0;i<Q;++i)
    {
        progress();
    }

}

void preprogress()
{
    for(long long i=0,j=0;i<N;++i)
    {
        Map[i][j]=height[i];
        Map2[i][j]=height[i];
    }
    for(long long j=1;(1<<j)<=N;++j)
    {
        for(long long i=0;(i+(1<<j)-1)<N;++i)
        {
            Map[i][j]=max(Map[i][j-1],Map[i+(1<<j-1)][j-1]);
            Map2[i][j]=min(Map2[i][j-1],Map2[i+(1<<j-1)][j-1]);
        }
    }
}

void progress()
{
    long long f,t;
    scanf("%lld%lld",&f,&t);
    long long len=t-f+1;
    f--;
    t--;
    len=log(1.0*len)/log(2.0);

    long long maxn=max(Map[f][len],Map[t-(1<<len)+1][len]);
    long long minn=min(Map2[f][len],Map2[t-(1<<len)+1][len]);
    printf("%lld\n",maxn-minn);

}
