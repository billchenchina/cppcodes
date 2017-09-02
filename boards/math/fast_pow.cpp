// fast pow
// updated on 2017/09/02
#include <bits/stdc++.h>
#define MODNUM p
using namespace std;

long long fast_pow(int a,int b,int p)
{
    if(b==1)
    {
        return a%p;
    }
    else if(b==0)
    {
        return 1;
    }
    else
    {
        long long res=fast_pow(a,b/2,p);
        res*=res;
        res%=p;
        if(b&1)
        {
            res*=a;
            res%=p;
        }
        return res;
    }
}

int main()
{
    long long a,b,p;
    cin>>a>>b>>p;
    cout<<fast_pow(a,b,p);
}
