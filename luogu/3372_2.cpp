#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;

namespace BCC
{
	class interval_tree
	{
	public:
		interval_tree(){}
		interval_tree(int L,int R,const std::vector<int> &v)
		{
            lazy_add=0;
            l_range=L;
            r_range=R;
            if(L==R)
            {
                l_child=r_child=NULL;
                sum=v[L];
                return;
            }
            else
            {
                #define mid (L+((R-L)>>1))
                l_child=new interval_tree(L,mid,v);
                r_child=new interval_tree(mid+1,R,v);
                #undef mid
                sum=l_child->sum+r_child->sum;
                return;
            }
		}
        interval_tree *l_child,*r_child;
        int l_range,r_range;
        int lazy_add;
        int sum;
        #define mid (l_range+((r_range-l_range)>>1))
        void add(int x,int y,int k)
        {
            if(l_range==x&&r_range==y)
            {
                lazy_add+=k;
                return;
            }
            else
            {
                sum+=k*(y-x+1);
                
                if(mid+1<=x)
                {
                    r_child->add(x,y,k);
                }
                else if(mid>=y)
                {
                    l_child->add(x,y,k);
                }
                else
                {
                    l_child->add(x,mid,k);
                    r_child->add(mid+1,y,k);
                }
                
            }
        }
        int querysum(int x,int y)
        {
            if(x==l_range&&y==r_range)
            {
                return sum+(y-x+1)*lazy_add;
            }
            sum+=(r_range-l_range+1)*lazy_add;
            add(l_range,mid,lazy_add);
            add(mid+1,r_range,lazy_add);
            lazy_add=0;
            if(y<=mid)
            {
                return l_child->querysum(x,y);
            }
            else if(x>=mid+1)
            {
                return r_child->querysum(x,y);
            }
            else
            {
                return l_child->querysum(x,mid)+r_child->querysum(mid+1,y);
            }
        }
        #undef mid
	};
}

int main()
{
	int N,M;
	cin>>N>>M;
	std::vector<int> v(N+1);
	for(int i=1;i<=N;++i)
	{
		cin>>v[i];
	}
	BCC::interval_tree *tree=new BCC::interval_tree(1,N,v);
    for(int i=1;i<=M;++i)
    {
        int opt;
        cin>>opt;
        switch(opt)
        {
            case 1:
            {
                int x,y,k;
                cin>>x>>y>>k;
                tree->add(x,y,k);
                break;
            }
            case 2:
            {
                int x,y;
                cin>>x>>y;
                cout<<tree->querysum(x,y)<<endl;
                break;
            }
            default:
                break;
        }
    }
}