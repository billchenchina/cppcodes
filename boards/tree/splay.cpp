#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000
struct splay_tree
{
    struct edge
    {
        int next;
        int to;
        int weight;
    };
    edge edges[MAXN];
    int first[MAXN];
    int pos;
    int root_p;
    splay_tree()
    {
        memset(edges,0,sizeof(edges));
        memset(first,0,sizeof(first));
        pos=0;
        root_p=1;
    }
    // node_pairs[i][j]:
    // means the node num from node i
    void init(const vector<vector<int> >&node_pairs)
    {
        for(int i=1;i<node_pairs.size();++i)
        {
            for(int j=0;j<node_pairs[i].size();++j)
            {
                edges[pos].to=node_pairs[i][j];
                edges[first[i]].next=pos;
                pos++;
            }
        }
    }

};
