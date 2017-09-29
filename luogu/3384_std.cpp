#include <bits/stdc++.h>

using namespace std;
const int maxn=300000;

// Global settings
// 关于全题的设定
int n,m,root;
int mod;

// 存边邻接表
int a[maxn];
int tt[maxn];
int first[maxn];
int nxt[maxn];
int last[maxn];
int k;
void add(int x,int y)
{
    a[++k]=y;
    tt[x]++;
    if(first[x]==0)first[x]=k;
    else nxt[last[x]]=k;
    last[x]=k;
}

// segment tree
// 线段树
struct seg_tree
{
    int l;
    int r;
    int v;
    int lazy;
} node[2*maxn];

void build_seg_tree(int u,int l,int r)
{
    int mid=(l+r)/2;
    node[u].l=l;
    node[u].r=r;
    if(l==r)return;
    build_seg_tree(u*2,l,mid);
    build_seg_tree(u*2+1,mid+1,r);
}

void down(int u)
{
    if(node[u].lazy==0)return;
    node[u].v+=node[u].lazy*(node[u].r-node[u].l+1)%mod;
    node[u*2].lazy+=node[u].lazy;
    node[u*2+1].lazy+=node[u].lazy;
    node[u].lazy=0;
}

void change(int u,int l,int r,int cont)
{
    if(node[u].l>r||node[u].r<l)return;
    if(node[u].l>=l&&node[u].r<=r)
    {
        node[u].lazy+=cont;
        down(u);
        return;
    }
    change(u*2,l,r,cont);
    change(u*2+1,l,r,cont);
    down(u*2);
    down(u*2+1);
    node[u].v=(node[u*2].v+node[u*2+1].v)%mod;
}

int query(int u,int l,int r)
{
    if(node[u].l>r||node[u].r<l)return 0;
    if(node[u].l>=l&&node[u].r<=r)return (node[u].v)%mod;
    down(u*2);
    down(u*2+1);
    return(query(u*2,l,r)+query(u*2+1,l,r))%mod;
}

// About graph
// 树相关
//  For dfs(int,int)
int size[maxn];
int r[maxn];
int father[maxn];

void dfs(int u,int fa)
{
    size[u]=1;
    r[u]=r[fa]+1;
    father[u]=fa;
    for(int i=first[u]; i; i=nxt[i])
        if(a[i]!=fa)
        {
            dfs(a[i],u);
            size[u]+=size[a[i]];
        }
}

//  For dfs2(int,int)
int top[maxn];
int tid[maxn];
int tot;
int rank[maxn];
int val[maxn];
int e[maxn];

void dfs2(int u,int virtual_root)
{
    int mson=0;
    top[u]=virtual_root;
    tid[u]=++tot;
    rank[tid[u]]=tot;
    change(1,tot,tot,val[u]);
    if(tt[u]==1&&u!=root)
    {
        e[u]=u;
        return;
    }
    for(int i=first[u]; i>0; i=nxt[i])
        if(size[a[i]]<size[u]&&size[a[i]]>size[mson])mson=a[i];
    dfs2(mson,virtual_root);
    e[u]=e[mson];
    for(int i=first[u]; i>0; i=nxt[i])
        if(size[a[i]]<size[u]&&a[i]!=mson)
        {
            dfs2(a[i],virtual_root);
            e[u]=e[a[i]];
        }
}
void schange(int x,int y,int cont)
{
    while(top[x]!=top[y])
    {
        if(r[top[x]]<r[top[y]])swap(x,y);
        change(1,tid[top[x]],tid[x],cont);
        x=father[top[x]];
    }
    if(tid[x]>tid[y])swap(x,y);
    change(1,tid[x],tid[y],cont);
}
int squery(int x,int y)
{
    int ans=0;
    while(top[x]!=top[y])
    {
        if(r[top[x]]<r[top[y]])swap(x,y);
        ans+=query(1,tid[top[x]],tid[x]);
        ans%=mod;
        x=father[top[x]];
    }
    if(tid[x]>tid[y])swap(x,y);
    ans+=query(1,tid[x],tid[y]);
    ans%=mod;
    return ans;
}

// main()
int main()
{
    cin>>n>>m>>root>>mod;
    for(int i=1; i<=n; i++)
    {
        cin>>val[i];
    }
    for(int i=1; i<=n-1; i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
        add(y,x);
    }
    build_seg_tree(1,1,n);
    dfs(root,0);
    dfs2(root,root);
    for(int i=1; i<=m; i++)
    {
        int opt;
        cin>>opt;
        if(opt==1)
        {
            int x,y,z;
            cin>>x>>y>>z;
            schange(x,y,z);
        }
        if(opt==2)
        {
            int x,y;
            cin>>x>>y;
            cout<<squery(x,y)%mod<<endl;
        }
        if(opt==3)
        {
            int x,y;
            cin>>x>>y;
            change(1,tid[x],tid[e[x]],y);
        }
        if(opt==4)
        {
            int x;
            cin>>x;
            cout<<query(1,tid[x],tid[e[x]])%mod<<endl;
        }
    }
    return 0;
}
