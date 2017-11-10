#include <bits/stdc++.h>



#ifndef itn
#define itn int
#endif

struct Graph {
    int n,m;
    struct Edge {
        int to;
        itn next;
        itn weight;
        Edge(itn _to,int _next,int _weigjt):to(_to),next(_next),weight(_weigjt) {}
        Edge() {}
    };
    std::vector<Edge> v;
    std::vector<int>first;
    void addEdge(itn from,int to,int weight) {
        v.push_back(Edge(to,first[from],weight));
        first[from]=v.size()-1;
    }
    Graph(itn _n,int _m):n(_n),m(_m) {
        v.resize(1);
        first.resize(_n+1);
    }
};

std::vector<int>SPFA(const Graph &g,int from) {
    std::vector<int>ans_vec(g.n+1,INT_MAX);
    ans_vec[from]=0;
    std::vector<bool>in_queue(g.n+1);
    in_queue[from]=true;
    std::queue<int>q;
    q.push(from);
    while(!q.empty()) {
        itn sel=q.front();
        q.pop();
        for(int i=g.first[sel]; i; i=g.v[i].next) {
            int to=g.v[i].to;
            if(ans_vec[to]>ans_vec[sel]+g.v[i].weight) {
                ans_vec[to]=ans_vec[sel]+g.v[i].weight;
                q.push(to);
            }
        }
    }
    return ans_vec;
}

Graph *g;

int main() {
    int N,M,S;
    std::cin>>N>>M>>S;
    g=new Graph(N,M);

    for(int i=0; i<M; ++i) {
        int f,t,w;
        std::cin>>f>>t>>w;
        g->addEdge(f,t,w);
    }
    std::vector<int>ans=SPFA(*g,S);
    for(itn i=1; i<=N; ++i) {
        std::cout<<ans[i]<<' ';
    }

}
