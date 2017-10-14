#include <bits/stdc++.h>

using namespace std;
#define bcc
#ifdef bcc
#define fin cin
#define fout cout
#else
ifstream fin("count.in");
ofstream fout("count.out");
#endif // bcc
int main()
{
    // now brute force
    int n,m;
    fin>>n>>m;
    vector<int>vec(m+1);
    for(int i=1;i<=m;++i)
    {
        fin>>vec[i];
    }
    int ans=0;
    for(int i=1;i<=n;++i)
    {
        bool ok=false;
        for(int j=1;j<=m;++j)
        {
            if(i%vec[j]==0)
            {
                ok=true;
            }
        }
        if(!ok)ans++;
    }
    fout<<ans;
}