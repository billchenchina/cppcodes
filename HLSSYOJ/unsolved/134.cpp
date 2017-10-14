#include <bits/stdc++.h>

using namespace std;
#define bcc
#ifdef bcc
#define fin cin
#define fout cout
#else
ifstream fin("kth.in");
ofstream fout("kth.out");
#endif // bcc
int main()
{
    long long n,k;
    fin>>n>>k;
    vector<long long>vec(n+1);
    for(long long i=1; i<=n; ++i)
    {
        fin>>vec[i];
    }
    vector<long long>ans;
    for(long long l=1;l<=n;++l)
    {
        for(long long len=1;l+len<=n+1;len+=2)
        {
            long long r=l+len;
            vector<long long>tmp(vec.begin()+l,vec.begin()+r);
            sort(tmp.begin(),tmp.end());
            ans.push_back(tmp[len/2]);
        }
    }
    sort(ans.begin(),ans.end(),greater<long long>());
    fout<<ans[k-1];
}