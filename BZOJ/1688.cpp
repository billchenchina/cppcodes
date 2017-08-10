#include <bits/stdc++.h>
using namespace std;

inline void add(int &cow,int place) {
    cow|=(1<<(place-1));
}
int main() {
    int N,D,K;
    cin>>N>>D>>K;
    vector<int>cow(N,0);
    for(int i=0; i<N; ++i) {
        int amount;
        cin>>amount;
        for(int j=0; j<amount; ++j) {
            int _d;
            scanf("%d",&_d);
            add(cow[i],_d);
        }
    }
    int maxn=0;
    for(int i=0; i<(1<<D); ++i) {
        // if the i is legal
        if(__builtin_popcount(i)<=K){
            int ttl=0;
            for(int j=0;j<N;++j) {
                // if the cow[j] can be calculated in answer
                if((cow[j]|i)==i)ttl++;
            }
            if(ttl>maxn)maxn=ttl;
        }
    }
    cout<<maxn;
}
