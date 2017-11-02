// Now bad version
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    struct Edge *first;
    int level;
} Nodes[10002];

struct Edge
{
    Node *to;
    Edge *next;
    int cap;
    int flow;
};

void addEdge(Node *from,Node *to,int cap)
{
    Edge *e=new Edge;
    e->to=to;
    e->cap=cap;
    e->flow=0;
    e->next=from->first;
    from->first=e;
}

void bfs(Node *a)
{
    a->level=1;
    queue<Node*>q;
    q.push(a);
    while(!q.empty())
    {
        Node *u=q.front();
        q.pop();
        for(Edge *e=u->first; e; e=e->next)
        {
            Node *v=e->to;
            if(v->level==0)
            {
                v->level=u->level+1;
                q.push(v);
            }
        }
    }
}

int augpath(Node *u,Node *T,int max_aug)
{
    if(u==T)
    {
        return max_aug;
    }
    int ans=0;
    for(Edge *e=u->first; e; e=e->next)
    {
        Node *v=e->to;
        if(v->level==u->level+1&&e->flow< e->cap)
        {
            int z=augpath(v,T,max(max_aug,e->cap-e->flow));
            if(z>0)
            {
                e->flow+=z;
                return z;
            }
        }
    }
    return 0;
}

int main()
{
    int N,M,S,T;
    cin>>N>>M>>S>>T;
    for(int i=0; i<M; ++i)
    {
        int u,v,w;
        cin>>u>>v>>w;
        addEdge(&Nodes[u],&Nodes[v],w);
    }
    bfs(&Nodes[S]);
    int ans=0;
    for(;;)
    {
        int aug=augpath(&Nodes[S],&Nodes[T],INT_MAX);
        if(aug==0)break;
        ans+=aug;
    }
    cout<<ans;
}
