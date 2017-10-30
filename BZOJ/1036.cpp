#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    int to;
    Edge *next;
};

Edge *edges[30001];

// 加边
void connect(int a,int b)
{
    Edge *now=new Edge;
    now->to=b;
    now->next=edges[a];
    edges[a]=now;
}

void read(int&b)
{
    char a;
    int res=0,flag=1;
    a=getchar();
    while(!isdigit(a))
    {
        if(a=='-')
        {
            flag=-1;
        }
        a=getchar();
    }
    while(isdigit(a))
    {
        res=res*10+a-'0';
        a=getchar();
    }
    b=res;
}

int n;

#define mid ((l_r+r_r)>>1)

struct treeNode
{
    int l_r;
    int r_r;
    treeNode *l_c;
    treeNode *r_c;
    treeNode(int l,int r)
    {
        if(l==r)
        {
            l_r=l;
            r_r=r;
            l_c=r_c=NULL;
        }
        else
        {
            l_r=l;
            r_r=r;
            l_c=new treeNode(l,mid);
            r_c=new treeNode(mid+1,r);
        }
    }
    void
};
#undef mid

int main()
{
    read(n);
    for(int i=0; i<n-1; ++i)
    {
        int a,b;
        read(a);
        read(b);
        connect(a,b);
    }

}
