#include <bits/stdc++.h>
using namespace std;

typedef
long long ll;
/////////////////////// Graph start
struct Edge {
    int to, next;
    int w;
}e[12000];

int e_cnt = 1;
int first[3000];

void addedge(int s, int t, int w)
{
    e[e_cnt].to = t; e[e_cnt].w = w;
    e[e_cnt].next = first[s];
    first[s] = e_cnt;
    e_cnt ++;
}
/////////////////////// Graph end

/////////////////////// Dijkstra start

ll shortest[3000];

bool operator < (pair<int, int> a, pair<int, int>b) {
    return a.second > b.second;
}


/////////////////////// Dijkstra end

/////////////////////// main() start

int main()
{
    int n, m, S, T;
    cin >> n >> m >> S >> T;
    memset(first, 0, sizeof first);
    memset(shortest, 0x3f, sizeof shortest);
    shortest[S] = 0;
    for(int i = 0; i < m; ++i) {
        int s, t, w;
        cin >> s >> t >> w;
        addedge(s, t, w);
        addedge(t, s, w);
    }
    priority_queue<pair<int, int> >pq;
    pq.push(make_pair(S, 0));
    while(!pq.empty()) {
        auto p = pq.top();pq.pop();
        for(int i = first[p.first]; i; i = e[i].next) {
#define u p.first
#define v e[i].to
#define ed e[i]
            if(shortest[u] + ed.w < shortest[v]) {
                shortest[v] = shortest[u] + ed.w;
                pq.push(make_pair(v, shortest[v]));
            }
#undef ed
        }
    }
    cout << shortest[T];

}
