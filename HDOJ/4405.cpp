#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n,m;

    while(cin>>n>>m)
    {
        if(n==0&&m==0)
        {
            return 0;
        }
        else
        {
            vector<int>fly(n+1,0);
            for(int i=0;i<m;++i)
            {
                int fro,to;
                cin>>fro>>to;
                fly[fro]=to;
            }
            vector<double>dp_val(n+1,0);
            for(int i=n-1;i>=0;--i)
            {
                if(fly[i])
                {
                    dp_val[i]=dp_val[fly[i]];
                    continue;
                }
                else
                {
                    for(int j=1;j<=6;++j)
                    {
                        if(i+j>=n)
                        {
                            dp_val[i]+=dp_val[n]/6;
                        }
                        else
                        {
                            dp_val[i]+=dp_val[i+j]/6;
                        }
                    }
                    dp_val[i]++;
                }
            }
            cout<<fixed<<setprecision(4)<<dp_val[0]<<endl;
        }
    }
}

