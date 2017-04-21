#include <iostream>
#include <queue>
using namespace std;
struct node {
    int time;
    int num;
    node(int n,int t) {
        this->time=t;
        this->num=n;
    }
};

int main() {
    bool vis[100001]= {0};
    int from,to;
    cin>>from>>to;
    if(from>=to) {
        cout<<(from-to);
        return 0;
    }
    queue<node>q;
    q.push(node(from,0));
    vis[from]=1;
    while(!q.empty()) {
        node n=q.front();
        q.pop();
        int time=n.time;
        int num=n.num;
        if(num+1==to) {
            cout<<time+1;
            return 0;
        } else if(vis[num+1]==0) {
            vis[num+1]=1;
            q.push(node(num+1,time+1));
        }
        if(num-1==to) {
            cout<<time+1;
            return 0;
        } else if(num-1>=0&&vis[num-1]==0) {
            vis[num-1]=1;
            q.push(node(num-1,time+1));

        }
        if(num*2==to) {
            cout<<time+1;
            return 0;
        } else if(num*2<=100000&&vis[num*2]==0) {
            vis[num*2]=1;
            q.push(node(num*2,time+1));
        }
    }
}
