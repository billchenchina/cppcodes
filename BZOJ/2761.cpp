
#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        int N;
        scanf("%d",&N);
        set<int>s;
        vector<int>v;
        while(N--) {
            int tmp;
            scanf("%d",&tmp);
            if(s.find(tmp)==s.end()) {
                s.insert(tmp);
                v.push_back(tmp);
            }

        }
        for(vector<int>::iterator iter=v.begin(); iter!=v.end(); iter++) {
            if(iter+1!=v.end())
                printf("%d ",*iter);
            else printf("%d\n",*iter);
        }
    }
}
