#include <bits/stdc++.h>

using namespace std;
struct node
{
    vector<int>child;
    int id;
    int value;
    int dp_val;
    int dp(int);
    node()
    {
        child.clear();
    }
    node(int _id,int _value)
    {
        id=_id;
        value=_value;
    }
};
node node_list[16001];
int node::dp(int father)
{
    if(dp_val)return dp_val;
    int ret=value;
    for(int i=0; i<child.size(); ++i)
    {
        int child_id=child[i];
        if(child_id!=father)
        {
            int child_dp=node_list[child_id].dp(id);
            ret+=(child_dp>0?child_dp:0);
        }
    }
    dp_val=ret;
    return ret;
}
inline void connect(int father,int son)
{
    node_list[father].child.push_back(son);
}

int main()
{
    ios::sync_with_stdio(false);
    int N;
    cin>>N;
    for(int i=1; i<=N; ++i)
    {
        cin>>node_list[i].value;
        node_list[i].id=i;
    }
    for(int i=0; i<N-1; ++i)
    {
        int father,son;
        cin>>father>>son;
        connect(father,son);
        connect(son,father);
    }
        int maxn=-1;
    for(int i=1;i<=N;++i)
    {
        int dp_val=node_list[i].dp(i);
        if(maxn<dp_val)maxn=dp_val;
    }
    cout<<maxn;
}















