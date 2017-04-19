#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        vector<int>v,v2;
        int n;
        cin>>n;
        for(int i=0; i<n; i++) {
            int tmp;
            cin>>tmp;
            v.push_back(tmp);
            v2.push_back(0);
        }
        if(n==1) {
            cout<<v[0]<<endl;
            continue;
        }
        if(n==2) {
            cout<<max(v[0],v[1])<<endl;
            continue;
        }
        v2[0]=v[0];
        v2[1]=max(v[0],v[1]);
        for(int j=2; j<v.size(); j++) {
            v2[j]=max(v2[j-1],v2[j-2]+v[j]);
        }
        cout<<v2[v.size()-1]<<endl;
    }


    return 0;
}
