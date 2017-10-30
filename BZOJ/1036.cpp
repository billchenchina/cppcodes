#include <bits/stdc++.h>

using namespace std;

void read(int&b)
{
    char a;
    int res=0,flag=1;
    a=getchar();
    while(!isdigit(a))
    {
        if(a=='-')
        {
            flag=-1;
        }
        a=getchar();
    }
    while(isdigit(a))
    {
        res=res*10+a-'0';
        a=getchar();
    }
    b=res;
}

int read()
{
    int a;
    read(a);
    return a;
}

int n;

#define mid ((l_r+r_r)>>1)

struct treeNode
{
    int l_r;
    int r_r;
    int sum;
    int maxn;
    treeNode *l_c;
    treeNode *r_c;
    treeNode(int l,int r)
    {
        if(l==r)
        {
            l_r=l;
            r_r=r;
            l_c=r_c=NULL;
        }
        else
        {
            l_r=l;
            r_r=r;
            l_c=new treeNode(l,mid);
            r_c=new treeNode(mid+1,r);
        }
    }
    void setValue(int l,int r,int val)
    {
        if(l>=mid+1)
        {
            this->r_c->setValue(l,r,val);
        }
        else if(r<=mid)
        {
            this->l_c->setValue(l,r,val);
        }
        else
        {
            this->l_c->setValue(l,mid,val);
            this->r_c->setValue(mid+1,r,val);
        }
        this->sum=this->l_c->sum
                  +this->r_c->sum;
        this->maxn=max(this->l_c->maxn,
                       this->r_c->maxn
                      );
    }
    int queryMax(int l,int r)
    {
        if(l==l_r&&r==r_r)
            return this->maxn;
        else
        {
            if(l>=mid+1)
            {
                return this->r_c->queryMax(l,r);
            }
            else if(r<=mid)
            {
                return this->l_c->queryMax(l,r);
            }
            else
            {
                return max(l_c->queryMax(l,mid),
                           r_c->queryMax(mid+1,r)
                          );
            }
        }
    }
    int querySum(int l,int r)
    {
        if(l==l_r&&r==r_r)
        {
            return this->sum;
        }
        else if(l>=mid+1)
        {
            return this->r_c->querySum(l,r);
        }
        else if(r<=mid)
        {
            return this->l_c->querySum(l,r);
        }
        else
        {
            return this->l_c->querySum(l,mid)+
                   this->r_c->querySum(mid+1,r);
        }
    }
};
#undef mid

struct Node
{
    int dfn;
    struct Edge *first;
    bool visited;
    struct Chain *chain;
    Node *father;
    Node *maxChild;
    int size;
    int depth;
} nodes[30000+1];

struct Edge
{
    Node *to;
    Edge *next;
};

struct Chain
{
    Node *top;
};


void connect(int fa,int son)
{
    Node *u=&nodes[fa];
    Node *v=&nodes[son];
    Edge *e=new Edge;
    e->to=v;
    e->next=u->first;
    u->first=e;
}

int dfn=1;

void dfs1(Node *u)
{
    u->size=1;
    u->dfn=dfn;
    dfn++;
    u->visited=true;
    for(Edge *e=u->first; e; e=e->next)
    {
        Node *v=e->to;

        if(v->visited==false)
        {
            v->depth=u->depth+1;
            v->father=u;
            dfs1(v);
            u->size+=v->size;
            if(u->maxChild==NULL||u->maxChild->size<v->size)
            {
                u->maxChild=v;
            }
        }
    }
}

void dfs2(Node *u)
{
    if(u->father==NULL||u!=u->father->maxChild)
    {
        u->chain=new Chain;
        u->chain->top=u;
    }
    else
    {
        u->chain=u->father->chain;
    }
    if(u->maxChild!=NULL)
    {
        dfs2(u->maxChild);
    }
    for(Edge *e=u->first; e; e=e->next)
    {
        Node *v=e->to;
        if(v->father==u&&v!=u->maxChild)
        {
            dfs2(v);
        }
    }
}
// missing 
//     change()
//     queryMax()
//     querySum()

int main()
{
    read(n);
    for(int i=0; i<n-1; ++i)
    {
        int a,b;
        read(a);
        read(b);
        connect(a,b);
        connect(b,a);
    }
    nodes[1].depth=1;
    dfs1(&nodes[1]);
    dfs2(&nodes[1]);
    treeNode *root=new treeNode(1,n);
    int q;
    read(q);
    char opt[20];
    for(int i=0;i<q;++i)
    {
        scanf("%s",opt);
        if(strcmp(opt,"CHANGE"))
        {
            int u,val;
            u=read();
            val=read();
            change(&nodes[u],val);
        }
        else if(strcmp(opt,"QMAX"))
        {
            int u,v;
            u=read();
            v=read();
            printf("%d",queryMax(&nodes[u],&nodes[v]));
        }
        else
        {
            int u,v;
            u=read();
            v=read();
            printf("%d",querySum(&nodes[u],&nodes[v]));
        }
    }
}
