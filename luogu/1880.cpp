// Now RE
// Leave it unfinished

#include <bits/stdc++.h>

using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    int N;
    cin>>N;
    vector<vector<int> >dp_map1(N,vector<int>(N+1,-1));
    vector<int>amount(2*N);
    for(int i=0;i<N;++i)
    {
        cin>>amount[i];
        amount[i+N]=amount[i];
    }
    int minn=INT_MAX;
    {
        int ttlrange=2;
        for(int j=0;j<N;++j)
        {
            dp_map1[j][ttlrange]=amount[j]+amount[j+1];
        }
    }

    for(int ttlrange=3;ttlrange<=N;++ttlrange)
    {
        for(int start=0;start<N;++start)
        {
            int minn=INT_MAX;
            for(int firstrange=0;firstrange<=ttlrange;++firstrange)
            {
                if(minn>dp_map1[start][firstrange]+dp_map1[start+firstrange][ttlrange-firstrange])
                {
                    minn=dp_map1[start][firstrange]+dp_map1[start+firstrange][ttlrange-firstrange];

                }
            }
            dp_map1[start][ttlrange]=minn;
        }
    }

    cout<<dp_map1[0][N];
}

