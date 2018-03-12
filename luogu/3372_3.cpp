#include <bits/stdc++.h>
using namespace std;

#define int long long

struct SegTree
{
    SegTree *l_child,*r_child;
    int l_range,r_range;
    int sum_value;
    int lazy_add;
    SegTree(int l,int r):l_range(l), r_range(r), lazy_add(0), sum_value(0)
    {
        if(l == r)
        {
            l_child = r_child = NULL;
        }
        else
        {
            int mid = l + (r-l)/2;
            l_child = new SegTree(l, mid);
            r_child = new SegTree(mid+1, r);
        }
    }
    void add(int l, int r, int k)
    {
        assert(l<=r);
        if(l <= l_range && r_range <= r)
        {
            lazy_add += k;
            sum_value += k*(r_range - l_range + 1);
            return;
        }
        else
        {
            int mid = l_range + (r_range-l_range)/2;
            if(r<=mid) l_child->add(l, r, k);
            else if(l>mid) r_child->add(l, r, k);
            else {
            l_child->add(l, mid, k);
            r_child->add(mid+1, r, k);
}
            sum_value += (r-l+1)*k;
        }
    }
    void push_down()
    {
        if(!lazy_add)
            return;
        int mid = l_range + (r_range-l_range)/2;
        if(l_child)
            l_child->add(l_range, mid, lazy_add);
        if(r_child)
            r_child->add(mid+1, r_range, lazy_add);
        lazy_add = 0;
    }
    int query(int l, int r)
    {
        assert(l>=l_range && r<= r_range);
        int mid = l_range + (r_range-l_range)/2;
        if(l==l_range && r==r_range)
        {
            return sum_value;
        }
        else
        {
            push_down();
            if(r<=mid)
            {
                return l_child->query(l,r);
            }
            else if(l>=mid+1)
            {
                return r_child->query(l,r);
            }
            else
            {
                return l_child->query(l,mid)+ r_child->query(mid+1,r);
            }
        }
    }
};
#undef int
int main()
{
#define int long long
    int N,M;
    cin>>N>>M;
    SegTree *tree = new SegTree(1,N);
    for(int i=1; i<=N; ++i)
    {
        int x;
        cin>>x;
        tree->add(i,i,x);
    }
    for(int i=0; i<M; ++i)
    {
        int opt;
        cin>>opt;
        if(opt==1)
        {
            int x,y,k;
            cin>>x>>y>>k;
            tree->add(x,y,k);
        }
        else
        {
            int x,y;
            cin>>x>>y;
            cout << tree->query(x,y) << endl;
        }
    }
}
