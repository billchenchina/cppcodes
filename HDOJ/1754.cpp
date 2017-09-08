#include <bits/stdc++.h>
using namespace std;
#define MAXN 250001
#define mid(x,y) ((x)+((y)-(x))/2)
struct node
{
    long long l_range;
    long long r_range;
    long long maxn;
    static void init(long long o=1);
    static void changeValue(long long,long long,long long o=1);
    static long long getMaxn(long long l,long long r,long long o=1);

}nodes[MAXN*4];
long long N,M;
long long arr[MAXN];

signed main()
{

    while(~scanf("%lld%lld",&N,&M))
    {

        for(long long i=0;i<N;++i)
        {
            scanf("%lld",&arr[1+i]);
        }
        node::init();
        for(long long i=0;i<M;++i)
        {
            char option;
            scanf("%c",&option);
            if(option=='Q')
            {
                long long l,r;
                scanf("%lld%lld",&l,&r);
                printf("%lld\n",node::getMaxn(l,r));
            }
            else
            {
                long long place,value;
                scanf("%lld%lld",&place,&value);
                node::changeValue(place,value);
            }
        }
    }
}
void node::init(long long o)
{
    if(o==1)
    {
        nodes[o].l_range=1;
        nodes[o].r_range=N;
        init(o<<1);
        init((o<<1)+1);
        nodes[o].maxn=max(nodes[o<<1].maxn,nodes[1+(o<<1)].maxn);
    }
    else
    {
        long long fa=o>>1;
        if(o&1)
        {
            nodes[o].l_range=mid(nodes[fa].l_range,nodes[fa].r_range)+1;
            nodes[o].r_range=nodes[fa].r_range;
        }
        else
        {
            nodes[o].r_range=mid(nodes[fa].l_range,nodes[fa].r_range);
            nodes[o].l_range=nodes[fa].l_range;
        }
        if(nodes[o].l_range==nodes[o].r_range)
        {
            nodes[o].maxn=arr[nodes[o].l_range];
        }
        else
        {
            init(o<<1);
            init((o<<1)+1);
            nodes[o].maxn=max(nodes[o<<1].maxn,nodes[1+(o<<1)].maxn);
        }
    }
}

void node::changeValue(long long place,long long value,long long o)
{
    if(nodes[o].l_range==nodes[o].r_range)
    {
        nodes[o].maxn=value;
    }
    else
    {
        if(mid(nodes[o].l_range,nodes[o].r_range)>=place)
        {
            changeValue(place,value,o<<1);
        }
        else
        {
            changeValue(place,value,1+(o<<1));
        }
        nodes[o].maxn=max(nodes[o<<1].maxn,nodes[1+(o<<1)].maxn);
    }
}



long long node::getMaxn(long long l,long long r,long long o)
{
    if(nodes[o].l_range==l&&nodes[o].r_range==r)
    {
        return nodes[o].maxn;
    }
    if(r<=mid(nodes[o].l_range,nodes[o].r_range))
    {
        return getMaxn(l,r,o<<1);
    }
    else if(l>=mid(nodes[o].l_range,nodes[o].r_range)+1)
    {
        return getMaxn(l,r,1+(o<<1));
    }
    else
    {
        return max(
                   getMaxn(l,mid(nodes[o].l_range,nodes[o].r_range),o<<1),
                   getMaxn(mid(nodes[o].l_range,nodes[o].r_range)+1,r,1+(o<<1))
                   );
    }
}
