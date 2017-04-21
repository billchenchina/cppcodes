#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
priority_queue <int> que;
int main() {
    int n;
    scanf("%d",&n);
    for(int i=0,x; i<n; i++) {
        scanf("%d",&x);
        que.push(-x);
    }
    int ans=0;
    for(int i=1,tmp;i<n;i++){
        tmp=que.top();
        ans-=que.top();
        que.pop();
        tmp+=que.top();
        ans-=que.top();
        que.pop();
        que.push(tmp);
    }
    cout<<ans;
    return 0;
}
