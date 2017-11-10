#include <bits/stdc++.h>

#define itn int
#define flase false
#define ture true
using std::vector;
using std::cin;
using std::cout;
using std::priority_queue;

struct Graph
{
    struct Edge
    {
        int to;
        int next;
        int weight;
        Edge(){}
        Edge(int _to,int _next,int _weight):to(_to),next(_next),weight(_weight){}
        bool operator <(const Edge &e)const
        {
            return weight>e.weight;
        }
    };
    itn n;
    int m;
    vector<Edge>e;
    vector<int>first;
    Graph(int _n,int _m):n(_n),m(_m)
    {
        e.resize(1);
        first.resize(_n+1);

    }
    void addEdge(int from,int to,int weight)
    {
        e.push_back(Edge(to,first[from],weight));
        first[from]=e.size()-1;
    }
};


int min_tree(const Graph &g)
{
    int ans=0;
    vector<bool>in_tree(g.n+1,0);
    in_tree[1]=true;
    priority_queue<Graph::Edge>pq;
    for(int i=g.first[1];i;i=g.e[i].next)
    {
        pq.push(g.e[i]);
    }
    while(!pq.empty())
    {
        Graph::Edge e=pq.top();pq.pop();
        int v=e.to;
        if(in_tree[v])
        {
            continue;
        }
        in_tree[v]=true;
        ans+=e.weight;
        for(int i=g.first[v];i;i=g.e[i].next)
        {
            Graph::Edge e=g.e[i];
            if(!in_tree[e.to])
            {
                pq.push(e);
            }
        }
    }
    return ans;
}

itn main()
{
    int N,M;
    cin>>N>>M;
    Graph *g=new Graph(N,M*2);
    for(int i=0;i<M;++i)
    {
        int x,y,z;
        cin>>x>>y>>z;
        g->addEdge(x,y,z);
        g->addEdge(y,x,z);
    }
    cout<<min_tree(*g);



}


