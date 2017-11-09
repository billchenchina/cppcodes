#include <bits/stdc++.h>


struct Edge
{
    int to;
    int length;
};

void addEdge(std::vector<Edge> &vec,int from,int to,int length)
{
    
}

int main()
{
    int N,M,S,T;
    std::cin>>N>>M>>S>>T;
    std::vector<Edge> vec(2*M);
    for(int i=0;i<M;++i)
    {
        int u,v,w;
        cin>>u>>v>>w;
        addEdge(vec,u,v,w);
        addEdge(vec,v,u,w);
    }
}
