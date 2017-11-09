#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    int to;
    int weight;
    Edge(int _to,int _weight):to(_to),weight(_weight){}
};

void addEdge(vector<Edge>&e,int a,int b,int w)
{
    e[a].push_back(Edge(b,w));
}

int main()
{
    int N,M;
    cin>>N>>M;
    vector<Edge> v[N];
    for(int i=0;i<M;++i)
    {
        int a,b,w;
        cin>>a>>b>>w;
        addEdge(v,a,b,w);
        addEdge(v,b,a,w);
    }
    priority_queue<Edge>q;
}