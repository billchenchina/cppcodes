#include <bits/stdc++.h>

using namespace std;


long long XOR(long long a)
{
    if((a+1)%4==0)
    {
        return 0;
    }
    else if((a-1)%4==0)
    {
        return 1;
    }
    else return a^XOR(a-1);
}

int main()
{
    int opt;
    cin>>opt;
    if(opt==1)
    {
        long long l,r;
        cin>>l>>r;
        l--;
        cout<<(XOR(l)^XOR(r));
    }
    else

    {
        long long n;
        cin>>n;
#ifdef MOD
#undef MOD
#endif
#define MOD 260817
        long long ans[100001];
        ans[2]=1;
        ans[3]=2;
        ans[4]=9;
        for(int i=5; i<=n; ++i)
        {
            ans[i]=((ans[i-1]+ans[i-2])%MOD)*(i-1);
            ans[i]%=MOD;
        }
        cout<<ans[n];
#undef MOD
    }



}
