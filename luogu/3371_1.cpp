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
        _e.at(counter).to=_v;
        _e.at(counter).length=_l;
        _e.at(counter).next=first[_u];
        first.at(_u)=counter;
        counter++;
    }
    vector<int>Dijkstra(int from)
    {
        vector<int>dis(n,INT_MAX);
        vector<bool>vis(n,0);
        dis.at(from)=0;
        // Preserve here is ok
        for(int i=first.at(from);~i;i=_e.at(i).next)
        {
            Edge &e=_e.at(i);
            int v=e.to;
            dis.at(v)=min(dis.at(v),e.length);
        }

        priority_queue<Edge>pq;
        pq.push(Edge(from,0));
        while(!pq.empty())
        {
            Edge e=pq.top();pq.pop();
            if(vis.at(e.to)&&from==e.to)continue;
            vis.at(e.to)=true;
            int u=e.to;
            for(int i=first.at(e.to);~i;i=_e.at(i).next)
            {
                Edge e=_e.at(i);
                int v=e.to;
                if(!vis.at(v))
                {
                    if(dis.at(v)>=dis.at(u)+e.length)
                    {
                        dis.at(v)=dis.at(u)+e.length;
                        e.to=v;
                        e.length=dis.at(v);
                        pq.push(e);
                    }
                }
            }
        }
        return dis;

    }
};

int main()
{
    int N,M,S;
    cin>>N>>M>>S;
    Graph G(N,M);
    for(int i=0;i<M;++i)
    {
        int f,g,w;
        cin>>f>>g>>w;
        G.addEdge(f-1,g-1,w);
    }
    vector<int>vec=G.Dijkstra(S-1);

    for(int i=0;i<N;++i)
    {
        cout<<vec.at(i)<<' ';
    }
}

