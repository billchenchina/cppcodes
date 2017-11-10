#include <bits/stdc++.h>

#define itn int
#define flase false
#define ture true
using std::vector;
using std::cin;
using std::cout;

struct Graph
{
    struct Edge
    {
        int to;
        int next;
        int weight;
        Edge(){}
        Edge(int _to,int _next,int _weight):to(_to),next(_next),weight(_weight){}
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

Graph *g;
itn main()
{
    int N,M;
    cin>>N>>M;
    g=new Graph(N,M);
    for(int i=0;i<M;++i)
    {
        int x,y,z;
        cin>>x>>y>>z;
        g->addEdge(x,y,z);
    }

}


