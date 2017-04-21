#include<iostream>
#include<cstdio>
using namespace std;
//求a的b次幂对m取余数。
long long quickMod(long long a,long long b,long long m)
{
    long long ans=1;
    while(b!=0)
    {
        if(b%2==1)
        {
            ans=(ans*a)%m;
            b--;
        }
        b=b/2;
        a=a*a%m;
    }
    return ans;
}
//a*b%m==(a%m*b)%m

long long quickModRec(long long a,long long b,long long m)
{
    long long ans;
    if(b==1)
        return a%m;
    else
    {
        ans=quickModRec(a,b/2,m);
        if(b%2==0)
            return ans*ans%m;
        else
            return ans*ans*a%m;
    }
}
int main()
{
    long long a=123456,b=101000009,m=99999;
    cout<<quickMod(a,b,m)<<endl<<quickModRec(a,b,m);
    return 0;
}


