#include <bits/stdc++.h>
#define DEBUG     for(int i=1;i<=n;++i)\
    {\
        cout<<root->query(i,i)<<' ';\
    }\
    cout<<endl;

using namespace std;

struct node
{
    node* lnode;
    node* rnode;
    int l_range;
    int r_range;
    int value;
    node(int _l,int _r)
    {
        l_range=_l;
        r_range=_r;
        value=0;
        if(_l==_r)
        {
            lnode=rnode=NULL;
        }
        else
        {
            int mid=_l+(_r-_l)/2;
            lnode=new node(_l,mid);
            rnode=new node(mid+1,_r);
        }
    }
    void add_value(int _l,int _r,int _val)
    {
        int mid=l_range+(r_range-l_range)/2;
        if(_l==l_range&&_r==r_range)
        {
            this->value+=_val;
        }
        else if(_l<=mid&&_r>=mid+1)
        {
            this->lnode->add_value(_l,mid,_val);
            this->rnode->add_value(mid+1,_r,_val);
        }
        else if(_r<=mid)
        {
            this->lnode->add_value(_l,_r,_val);

        }
        else if(_l>=mid+1)
        {
            this->rnode->add_value(_l,_r,_val);
        }
    }
    int query(int _l,int _r)
    {
        int ans=(_r-_l+1)*value;
        int mid=l_range+(r_range-l_range)/2;
        if(l_range==r_range)
        {
            return ans;
        }
        if(_l>=mid+1)
        {
            ans+=this->rnode->query(_l,_r);
        }
        else if(_r<=mid)
        {
            ans+=this->lnode->query(_l,_r);
        }
        else
        {
            ans+=this->lnode->query(_l,mid);
            ans+=this->rnode->query(mid+1,_r);
        }
        return ans;
    }
};


int main()
{
    int n,m;
    cin>>n>>m;
    node *root=new node(1,n);
    for(int i=1;i<=n;++i)
    {
        int val;
        cin>>val;
        root->add_value(i,i,val);
    }

    while(m--)
    {
        int opt;
        cin>>opt;
        if(opt==1)
        {
            int x,y,k;
            cin>>x>>y>>k;
            root->add_value(x,y,k);
        }
        else if(opt==2)
        {
            int x,y;
            cin>>x>>y;
            cout<<root->query(x,y)<<endl;
        }
    }
}
