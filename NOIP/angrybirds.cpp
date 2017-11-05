#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

#define check_for_ok() cout<<"ok"<<endl<<flush
#define ok check_for_ok();


using namespace std;

bool equal(const double&,const double&);
struct pig;
struct line;


namespace BCC_tools
{
namespace binary
{
int getbit(int x,int a)
{
    return x&(1<<a);
}

void setbit1(int &x,int a)
{
    x=x|(1<<a);
}

void setbit0(int &x,int a)
{
    int u=getbit(x,a);
    if(u)
    {
        x=x-(1<<a);
    }
}

void swapbit(int &x,int a)
{
    if(getbit(x,a))
    {
        x=x-(1<<a);
    }
    else
    {
        setbit1(x,a);
    }
}
}
}

struct pig
{
    double x;
    double y;
    pig() {}

    bool onLine(const line&);
};

struct line
{
    double a;
    double b;
    line() {}
    line(double _a,double _b):a(_a),b(_b) {}
};

bool pig::onLine(const line &l)
{
    if(equal(this->y,l.a*this->x*this->x+l.b*this->x))
    {
        return true;
    }
    return false;
}

const double eps=1e-6;

bool equal(const double &a,const double &b)
{
    if(fabs(a-b)<eps)
    {
        return true;
    }
    return false;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,m;
        cin>>n>>m;
        vector<pig>pigs(n);
        vector<vector<int> >lines(n,vector<int>(n));
        for(int i=0; i<n; ++i)
        {
            cin>>pigs[i].x>>pigs[i].y;
        }
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<i; ++j)
            {
                double xa=pigs[i].x,xb=pigs[j].x,
                       ya=pigs[i].y,yb=pigs[j].y;
                if(equal(xa,xb)&&!equal(ya,yb))
                {
                    continue;
                }
                double a=(ya*xb-xa*yb)/(xa*xb*(xa-xb)),
                       b=(ya*xb*xb-yb*xa*xa)/(xa*xb*(xb-xa));
                if(a>=0)continue;
                line l=line(a,b);
                for (int k = 0; k < n; ++k)
                {
                    if(pigs[k].onLine(l))
                    {
                        BCC_tools::binary::setbit1(lines[i][j],k);
                    }
                }
                lines[j][i]=lines[i][j];

            }

        }
        int status_table[300000];
        memset(status_table,0,sizeof(status_table));
        for(int s=1; s<(1<<n)-1; ++s)
        {
            int low0=0;
            for(; low0<n; low0++)
            {
                if(BCC_tools::binary::getbit(s,low0))
                {
                    break;
                }
            }
            status_table[s]=status_table[s-(1<<low0)]+1;
            for(int j=0; j<n; ++j)
            {
                if(j!=low0&&s!=(1<<j))
                {
                    int p =s& ~lines[j][low0];
                    status_table[s] = min(status_table[s], status_table[p] + 1);
                }
            }
        }
        cout<<status_table[(1 << n) - 1]<<endl;

    }
}
