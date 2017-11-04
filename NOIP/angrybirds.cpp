#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct pig
{
    double x;
    double y;
    pig(){}
};

struct line
{
    double a;
    double b;
    line(){}
    line(double _a,double _b):a(_a),b(_b){}
};

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
        vector<line>lines;
        for(int i=0;i<n;++i)
        {
            cin>>pigs[i].x>>pigs[i].y;
        }
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<i;++j)
            {
                double xa=pigs[i].x,xb=pigs[j].x,
                       ya=pigs[i].y,yb=pigs[j].y;
                if(equal(xa,xb)&&!equal(ya,yb))
                {
                    continue;
                }
                double a=(ya*xb-xa*yb)/(xa*xb*(xa-xb)),
                       b=(ya*xb*xb-yb*xa*xa)/(xa*xb*(xb-xa));
                lines.push_back(line(a,b));
            }
        }

    }
}
