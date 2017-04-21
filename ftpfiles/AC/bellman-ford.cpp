#include <cstdio>
#include <iostream>
#include <memory.h>
using namespace std;

int n,//num of point
    m;//num of line
int from,to;
int s[200];
struct line {
    int f;
    int t;
    int w;
} lines[500];

int main() {
    cin>>n>>m;
    for(int i=0; i<m; i++) {
        cin>>lines[i].f>>lines[i].t>>lines[i].w;
    }
    cin>>from>>to;
    memset(s,0x3f,sizeof(s));
    s[from]=0;


    for(int i=1; i<n; i++) {
        for(int j=0; j<m; j++) {
            if( s[lines[j].f] + lines[j].w < s[lines[j].t] ) {
                s[lines[j].t]=s[lines[j].f]+lines[j].w;
            }
        }
    }
    cout<<s[to];
    return 0;
}
