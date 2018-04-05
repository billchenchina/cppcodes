
#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int from;
    int to;
    int length;
    Edge(int _,int __,int ___):from(_),to(__),length(___){}
};

vector<Edge>edges[100010];

double dp[100010];

int N,M;

int main() {
    memset(dp,0,sizeof dp);

    scanf("%d%d",&N, &M);
    for(int i=0; i<M; ++i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);

        edges[a].push_back(Edge(a,b,c));
    }
    dp[N]=0;
    for(int i = N-1; i>=1; --i) {
        for(int j=0; j<edges[i].size(); ++j) {
            dp[i] += (dp[edges[i][j].to] + edges[i][j].length)/edges[i].size();
        }

    }
    printf("%.2lf", dp[1]);


}
