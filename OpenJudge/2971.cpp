#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
class pos {
public:
    int weizhi;
    int pre;
    int steps;
};
queue <pos> dl;
int used[1000000][2],usedl,ttl;
bool rslt;
bool visited[1000000];

int main() {
    int n,k,ttl=0;
    cin>>n>>k;
    dl.push({n,0,0});
    visited[n]=true;
    if(n>=k) {
        cout<<n-k;
        return 0;
    } else
        while(!dl.empty()) {
            pos tmp=dl.front();
            if(tmp.weizhi==k) {
                cout<<tmp.steps;
                return 0;
            }
            rslt=visited[tmp.weizhi+1];
            if(!rslt) {
                dl.push({tmp.weizhi+1,tmp.weizhi,tmp.steps+1});
            }
            if(tmp.weizhi-1>=0) {
                rslt=visited[tmp.weizhi-1];
                if(!rslt) {
                    dl.push({tmp.weizhi-1,tmp.weizhi,tmp.steps+1});
                }
            }
            if(tmp.weizhi*2<=100001){
            rslt=visited[tmp.weizhi*2];
            if(!rslt) {
                dl.push({tmp.weizhi*2,tmp.weizhi,tmp.steps+1});
            }}
            usedl++;
            used[usedl][0]=dl.front().weizhi;
            used[usedl][1]=dl.front().pre;
            visited[tmp.weizhi]=true;
            dl.pop();
        }
    return 0;
}