#include <bits/stdc++.h>

using namespace std;

struct segment_tree_node
{
    int l;
    int r;
    int sum;
    int lazy;
    segment_tree_node*l_child,*r_child;
    segment_tree_node(){}
    segment_tree_node(int _l,int _r)
    {
        l=_l;
        r=_r;
        if(l==r)
        {
            return;
        }
        else
        {
            l_child=new segment_tree_node(l,l+((r-l)>>1));
            r_child=new segment_tree_node(l+1+((r-l)>>1),r);
        }
    }
};

int main()
{
    int N,M;
    cin>>N>>M;
    vector<int> arr(N+1,0);
    for(int i=1; i<=N; ++i)
    {
        cin>>arr[i];
    }

}
