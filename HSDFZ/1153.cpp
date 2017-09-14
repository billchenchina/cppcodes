#include <bits/stdc++.h>
#define MOD 1012
using namespace std;

int ksm(int a,int b)
{
    if(b==0)
    {
        return 1;
    }
    else if(b==1)
    {
        return a%MOD;
    }
    else
    {
        if(b&1)
        {
            int ans1=ksm(a,b>>1);
            ans1*=ans1;
            ans1%=MOD;
            ans1*=a;
            ans1%=MOD;
            return ans1;
        }
        else
        {
            int ans1=ksm(a,b>>1);
            ans1*=ans1;
            ans1%=MOD;
            return ans1;
        }
    }
}
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<ksm(a,b)<<endl;

}
