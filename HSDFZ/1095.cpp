
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
bool rule(int a,int b);
priority_queue <int,vector<int>,greater<int> > a;
int main() {
    int ttl=0;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        a.push(tmp);
    }
    for(int i=1;i<n;i++){
        int tmp=a.top();
        a.pop();
        tmp+=a.top();
        a.pop();
        ttl+=tmp;
        a.push(tmp);
    }
    cout<<ttl;
    return 0;
}
