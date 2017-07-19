#include <iostream>
#include <algorithm>
#include <climits>
#include <cstdio>
using namespace std;
struct node {
    long long x;long long r;
};
struct cmp {
    bool operator ()(const node &n1,const node &n2) {
        return n1.x<n2.x;
    }
};
int main() {
    //freopen("3.in","r",stdin);
    long long L,N;
    cin>>L>>N;
    node nodes[100001];
    long long distmin;
    long long dist=0;
    long long nowpos=0;
    for(long long i=0; i<N; i++) {
        cin>>nodes[i].x>>nodes[i].r;
        dist+=nodes[i].x*nodes[i].r;
    }
    distmin=dist;
    sort(nodes,nodes+N,cmp());

    for(long long i=0; i<N; i++) {
        long long deltax=0;
        long long lpeople=0,rpeople=0;
        for(long long j=0; j<i; j++) {
            lpeople+=nodes[j].r;
        }
        for(long long j=i;j<N;j++){
            rpeople+=nodes[j].r;
        }
       // cout<<lpeople<<' '<<rpeople<<endl;
        //cout<<nodes[i].x<<' '<<nowpos<<endl;
        deltax-=(rpeople-lpeople)*(nodes[i].x-nowpos);
        //cout<<"deltax #"<<i+1<<": "<<deltax<<endl;
        nowpos=nodes[i].x;
        if(deltax>0) {
            dist+=deltax;
        } else {
            dist+=deltax;
            distmin=(distmin<dist?distmin:dist);
        }
    }
    long long deltax=0;
    for(long long j=0; j<N; j++) {
        deltax+=(L-nodes[j].x)*nodes[j].r;
    }
    long long distl=dist+deltax;
    distmin=distmin<distl?distmin:distl;
    cout<<distmin;
    return 0;
}