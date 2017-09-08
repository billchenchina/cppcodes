#include <bits/stdc++.h>

using namespace std;
#define MAXN 100001
long long n;
long long arr[MAXN];
inline void read(long long &x){
    /*
    x=0;
    int flag=1;
    char c=getchar();
    while(c<'0' || c>'9'){
        if(c=='-')flag=-1;
        c=getchar();
    }
    while(c>='0' && c<='9'){
        x=x*10+c-'0';
        c=getchar();
    }
    x*=flag;
    */
    scanf("%lld",&x);
}

struct node
{
    long long l_range;
    long long r_range;
    long long value;
    long long mid;
    static void init(long long);
    static void addValue(long long,long long,long long,long long);
    static long long getValue(long long,long long,long long);
};

node nodes[4*MAXN];


void node::init(long long o=1)
{
    //cout<<o<<' ';
    if(o==1)
    {
        nodes[o].l_range=1;
        nodes[o].r_range=n;
        nodes[o].mid=1+(n-1)/2;
        init(o<<1);
        init((o<<1)+1);
        nodes[o].value=nodes[o<<1].value+nodes[1+(o<<1)].value;
    }
    else
    {
        long long fa=o>>1;
        if(o&1)
        {
            nodes[o].l_range=nodes[fa].mid+1;
            nodes[o].r_range=nodes[fa].r_range;
        }
        else
        {
            nodes[o].l_range=nodes[fa].l_range;
            nodes[o].r_range=nodes[fa].mid;
        }
        nodes[o].value=0;
        nodes[o].mid=nodes[o].l_range+(nodes[o].r_range-nodes[o].l_range)/2;
        if(nodes[o].l_range==nodes[o].r_range)
        {
            nodes[o].value=arr[nodes[o].l_range];
            return;
        }
        else
        {
            init(o<<1);
            init((o<<1)+1);
            nodes[o].value=nodes[o<<1].value+nodes[1+(o<<1)].value;
        }
    }
}

void node::addValue(long long l,long long r,long long val,long long o=1)
{
    if(nodes[o].l_range==nodes[o].r_range)
    {
        nodes[o].value+=val;
        return;
    }
    else
    {
        if(nodes[o].mid>=r)
        {
            addValue(l,r,val,o<<1);
            nodes[o].value+=val*(r-l+1);
        }
        else if(nodes[o].mid+1<=l)
        {
            addValue(l,r,val,1+(o<<1));
            nodes[o].value+=val*(r-l+1);
        }
        else
        {
            addValue(l,nodes[o].mid,val,o<<1);
            addValue(nodes[o].mid+1,r,val,(o<<1)+1);
            nodes[o].value+=val*(r-l+1);
        }
    }
}
long long node::getValue(long long l,long long r,long long o=1)
{
    if(nodes[o].l_range==l&&nodes[o].r_range==r)
    {
        return nodes[o].value;
    }
    else if(r<=nodes[o].mid)
    {
        return getValue(l,r,o<<1);
    }
    else if(l>=nodes[o].mid+1)
    {
        return getValue(l,r,(o<<1)+1);
    }
    else
    {
        return getValue(l,nodes[o].mid,o<<1)
            +getValue(nodes[o].mid+1,r,1+(o<<1));
    }
}

int main()
{
    long long m;
    read(n);read(m);
    //cin>>n>>m;
    //cout<<endl;
    for(long long i=1; i<=n; ++i)
    {
        read(arr[i]);
        //cin>>val;
    }
    node::init();
    while(m--)
    {
        long long opt;
        read(opt);
        //cin>>opt;
        if(opt==1)
        {
            long long x,y,k;
            read(x);read(y);read(k);
            //cin>>x>>y>>k;
            node::addValue(x,y,k);
        }
        else if(opt==2)
        {
            long long x,y;
            read(x);read(y);
            //cin>>x>>y;
            printf("%ld\n",node::getValue(x,y));
            //cout<<node::getValue(x,y)<<endl;
        }
    }
}
