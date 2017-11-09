#include <bits/stdc++.h>
using namespace std;



struct Graph
{
    struct Edge
    {
        int to;
        int next;
        int length;
        bool operator<(const Edge &e)const
        {
            return length>e.length;
        }
        Edge(int i=-1):next(i){}
        Edge(int _to,int _length)
        {
            to=_to;
            length=_length;
        }
    };
    int n,m;
    vector<int>first;
    vector<Edge>_e;
    int counter;
    Graph(int _n,int _m)
    {
        n=_n;
        m=_m;
        first.resize(n,-1);
        _e.resize(m,-1);
        counter=0;
    }
    void addEdge(int _u,int _v,int _l)
    {
        _e[counter].to=_v;
        _e[counter].length=_l;
        _e[counter].next=first[_u];
        first[_u]=counter;
        counter++;
    }
    vector<int>Dijkstra(int from)
    {
        vector<int>dis(n,INT_MAX);
        vector<bool>vis(n,0);
        dis[from]=0;
        for(int i=first[from];~i;i=_e[i].next)
        {
            Edge &e=_e[i];
            int v=e.to;
            dis[v]=min(dis[v],e.length);
        }
        priority_queue<Edge>pq;
        pq.push(Edge(from,0));
        while(!pq.empty())
        {
            Edge e=pq.top();pq.pop();
            if(vis[e.to]&&from==e.to)continue;
            vis[e.to]=true;
            int u=e.to;
            for(int i=first[e.to];~i;i=_e[i].next)
            {
                Edge &e=_e[i];
                int v=e.to;
                if(!vis[v])
                {
                    if(dis[v]>dis[u]+e.length)
                    {
                        dis[v]=dis[u]+e.length;
                        e.to=v;
                        e.length=dis[v];
                        pq.push(e);
                    }
                }
            }
        }

    }
};

int main()
{

    int P,C,PB,PA1,PA2;
    cin>>C>>P>>PB>>PA1>>PA2;
    Graph g1(P,C*2);
    for(int i=0;i<C;++i)
    {
        int u,v,l;
        cin>>u>>v>>l;
        g1.addEdge(u-1,v-1,l);
        g1.addEdge(v-1,u-1,l);
    }
    int ans=0;
    vector<int>vec1=g1.Dijkstra(PB-1);
    ans+=min(vec1[PA1-1],vec1[PA2-1]);
    vector<int>vec2=g1.Dijkstra(PA1-1);
    ans+=vec2[PA2-1];
    cout<<ans;
}
