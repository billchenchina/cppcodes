#include <iostream>
#include <vector>
using namespace std;
int findancestor(vector<int>&v,int position);
int main() {
    int n,m;
    cin>>n>>m;
    vector<int>ancestor(n+1);
    for(int i=1; i<=n; i++) {
        ancestor[i]=i;
    }

    for(int i=0; i<m; i++) {
        int z;
        cin>>z;
            int node1,node2;
            cin>>node1>>node2;
            int anc1=findancestor(ancestor,node1);
            int anc2=findancestor(ancestor,node2);
        if(z==1) {
            if(anc1!=anc2)ancestor[anc1]=anc2;
        } else if(z==2) {
            if(anc1==anc2)cout<<"Y"<<endl;
            else cout<<"N"<<endl;
        }
    }
}

int findancestor(vector<int>&v,int position){
    if(v[position]==position)return position;
    if(v[position]){
        v[position]=findancestor(v,v[position]);
    }
    return v[position];
}
