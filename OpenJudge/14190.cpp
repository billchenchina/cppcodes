#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;
int g[10002][10002];
int nums[10002];
int father[10002];
int main() {
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=m; i++) {
        int a,b;
        cin>>a>>b;
        g[a][nums[a]]=b;
        nums[a]++;
        father[b]++;
    }
    queue<int>q;
    for(int i=1; i<=n; i++) {
        if(father[i]==0)q.push(i);
    }

    int solvedNum=0;
    while(!q.empty()) {
        int head=q.front();
        for(int i=0; i<nums[head]; i++) {
            int c=g[head][i];
            father[c]--;
            if(father[c]==0)q.push(c);
        }
        solvedNum++;
        q.pop();
    }
    if(solvedNum==n) {
        cout<<"o(กษ_กษ)o";
    } else {
        cout<<"T_T"<<endl<<n-solvedNum;
    }
    return 0;
}
