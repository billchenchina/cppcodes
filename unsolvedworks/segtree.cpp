#include <bits/stdc++.h>

using namespace std;

struct segment_tree_node
{
    int l;
    int r;
    int sum;
    int lazy;
};

segment_tree_node tree[400000];

void buildtree(const vector<int>&arr,int o=1)
{
    if(o==1)
    {
        tree[o].l=1;
        tree[o].r=arr.size();
        buildtree(arr,o<<1);
        buildtree(arr,(o<<1)+1);
        tree[o].sum=tree[o<<1].sum
                                +tree[(o<<1)+1].sum;
        return;
    }
    if(o&1)
    {
        tree[o].l=tree[o>>1].l;
        tree[o].r=(tree[o>>1].l+tree[o>>1].r)>>1;
        if(tree[o].l==tree[o].r)
        {
            return;
        }
    }
    else
    {
        tree[o].r=tree[o>>1].r;
        tree[o].l=1+(tree[o>>1].l+tree[o>>1].r)>>1;
        if(tree[o].l==tree[o].r)
        {
            return;
        }
    }
}

int main()
{
    int N,M;
    cin>>N>>M;
    vector<int> arr(N+1,0);
    for(int i=1;i<=N;++i)
    {
        cin>>arr[i];
    }
    buildtree(arr);
}