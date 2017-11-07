#include <bits/stdc++.h>

namespace BCC
{

    int gcd(int x,int y)
    {
        if(y==0){return x;}
        else return gcd(y,x%y);
    }
    struct frac
    {
        int up;
        int down;
        frac(int up,int down):up(up),down(down){}
        frac(){up=0,down=1;}
        void maintain()
        {
            int gcd=BCC::gcd(up,down);
            up=up/gcd;
            down=down/gcd;
        }
        friend bool operator<(const frac&f1,const frac &f2)
        {
            int a=f1.up*f2.down;
            int b=f2.up*f1.down;
            return a<b;
        }
        friend bool operator>(const frac&f1,const frac &f2)
        {
            return f2<f1;
        }
        friend bool operator==(const frac&f1,const frac &f2)
        {
            return (!(f1<f2))&&(!(f1>f2));
        }
    };
}

struct person
{
    int l;
    int r;
    friend bool operator<(const person &p1,const person &p2)
    {

    }
};


int main()
{
}
