#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    if(a<b)swap(a,b);
    if(b==0)return a;
    else return gcd(b,a%b);
}
int main()
{
    int a,b;
    cin>>a>>b;
    int gcd_=gcd(a,b);
    cout<<gcd_<<endl<<(a/gcd_)*b;
}