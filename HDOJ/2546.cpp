#include <bits/stdc++.h>

using namespace std;





int main()
{
    int n;
    while(cin>>n&&n!=0)
    {
        vector<int>value(n+1,0);
        int m;
        for(int i=1;i<=n;++i)
        {
            cin>>value[i];
        }
        cin>>m;
        vector<vector<int> >dp_map(n+1,vector<int>(m+1));
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                dp_map[i][j]=min();
            }
        }


    }
}

