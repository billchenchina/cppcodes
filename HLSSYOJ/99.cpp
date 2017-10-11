#include <bits/stdc++.h>

using namespace std;


long long divisor(long long n,long long a)
{
    return n/a;
}


int main()
{
    long long n;
    cin>>n;
    long long a,b,c;
    cin>>a>>b>>c;
    long long ans=0;
    ans+=divisor(n,a);
    ans+=divisor(n,b);
    ans+=divisor(n,c);
    long long d=a*b/__gcd(a,b);
    long long e=b*c/__gcd(b,c);
    long long f=a*c/__gcd(a,c);
    long long g=d*c/__gcd(c,d);
    ans-=divisor(n,d);
    ans-=divisor(n,e);
    ans-=divisor(n,f);
    ans+=divisor(n,g);
    cout<<n-ans;
}
