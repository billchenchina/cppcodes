#include <bits/stdc++.h>

using namespace std;


void dfs(const int i,vector<int> &List,
         const vector<int>father,
         const vector<vector<int> >sons,vector<int>&depth) {
    List.push_back(i);
    for(int j=0; j<sons[i].size(); j++) {
        depth[sons[i][j]]=depth[i]+1;
        dfs(sons[i][j],List,father,sons,depth);
        List.push_back(i);
    }
}
// find min
// Finished
void do_work(const int Node_num,const vector<int>depth,vector<vector<int> >&rmq) {

    for(int i=1; i<=Node_num; i++) {
        rmq[i][0]=depth[i];
    }
    /**
      * Some Questions here to be checked...
      * You will find an 20 in your output
      **/
    for(int j=1; (1<<j)<=Node_num; j++)
        for(int i=1; i+(1<<j)-1<=Node_num; i++) {
            cout<<' '<<i<<' '<<j<<' '<<i<<' '<<j-1<<' '<<((i+1)<<(j-1))<<' '<<j-1;
            rmq[i][j]=min(rmq[i][j-1],rmq[i+1<<(j-1)][j-1]);
        }
}

int main() {
    int T;
    cin>>T;
    while(T--) {
        int Node_num;
        cin>>Node_num;
        vector<int>father(Node_num+1,-1);
        vector<vector<int> >sons(Node_num+1,vector<int>());
        for(int i=0; i<Node_num-1; i++) {
            // fa => father
            // so => son
            int fa,so;
            cin>>fa>>so;
            father[so]=fa;
            sons[fa].push_back(so);
        }
        int root=1;
        // Find root
        while(father[root]!=-1) {
            root=father[root];
        }
        vector<int>v;
        vector<int>depth(Node_num+1,0);
        depth[root]=1;
        dfs(root,v,father,sons,depth);
        for(int i=0; i<v.size(); i++)cout<<fixed<<setw(2)<<v[i];
        cout<<endl;
        for(int i=0; i<v.size(); i++)cout<<fixed<<setw(2)<<depth[v[i]];

        vector<vector<int> >rmq(Node_num+1,vector<int>(Node_num+1));
        do_work(Node_num,depth,rmq);

        int M;
        cin>>M;
        while(M--) {
            int u,v;
            cin>>u>>v;
        }
    }
}
