#include <bits/stdc++.h>

using namespace std;


inline int amount(int x)
{
    if(x<4)
    {
        return x+1;
    }
    if(x>=4&&x<=11)
    {
        return x;
    }
    string str;
    stringstream ss;
    ss<<x;
    ss>>str;
    int dp_map[10][10][2]={0};
    int len=str.length();
    int maxn=str[0]-'0';
    for(int i=0; i<10; ++i)
    {
        if(i==4)
        {
            dp_map[len-1][i][0]=0;
            //<<"dp_map["<<len-1<<"]["<<i<<"]="<<0<<endl;
        }
        else
        {
            dp_map[len-1][i][0]=1;
            //<<"dp_map["<<len-1<<"]["<<i<<"]="<<1<<endl;
        }
        if(i==str[len-1]-'0'&&i!=4)
        {
            dp_map[len-1][i][1]=1;
        }
        else
        {
            dp_map[len-1][i][1]=0;
        }
    }
    for(int i=len-2; i>=1; --i)
    {
        for(int j=0; j<10; ++j)
        {
            if(j==4)
            {
                dp_map[i][j][0]=0;
                //<<"dp_map["<<i<<"]["<<j<<"]="<<0<<endl;
            }
            else if(j==6)
            {
                for(int k=0; k<10; ++k)
                {
                    if(k!=2)
                    {
                        dp_map[i][j][0]+=dp_map[i+1][k][0];
                        //<<"dp_map["<<i<<"]["<<j<<"]="<<dp_map[i][j][0]<<endl;
                    }
                }
            }
            else
            {
                for(int k=0; k<10; ++k)
                {
                    dp_map[i][j][0]+=dp_map[i+1][k][0];
                    //<<"dp_map["<<i<<"]["<<j<<"]="<<dp_map[i][j][0]<<endl;
                }
            }
            if(j==str[i]-'0')
            {
                for(int k=0;k<str[i-1]-'0';++k)
                {
                    dp_map[i][j][1]+=dp_map[i+1][k][0];
                }
                dp_map[i][j][1]+=dp_map[i+1][str[i-1]-'0'][1];
            }
        }
    }


    {
        int i=0;
        for(int j=0; j<str[i]-'0'; ++j)
        {
            if(j==4)
            {
                dp_map[i][j][0]=0;
                //<<"dp_map["<<i<<"]["<<j<<"]="<<dp_map[i][j][0]<<endl;
            }
            else if(j==6)
            {
                for(int k=0; k<10; ++k)
                {
                    if(k!=2)
                    {
                        dp_map[i][j][0]+=dp_map[i+1][k][0];
                        //<<"dp_map["<<i<<"]["<<j<<"]="<<dp_map[i][j][0]<<endl;
                    }
                }
            }
            else
            {
                for(int k=0; k<10; ++k)
                {
                    dp_map[i][j][0]+=dp_map[i+1][k][0];
                    //<<"dp_map["<<i<<"]["<<j<<"]="<<dp_map[i][j][0]<<endl;

                }
            }
        }
        int j=str[i]-'0';
        for(int k=0;k<str[i+1]-'0';++k)
        {
            dp_map[i][j][1]+=dp_map[i+1][k][0];
        }
        int k=str[i+1]-'0';
        dp_map[i][j][1]+=dp_map[i+1][k][1];
    }

    int ans=0;
    for(int i=0;i<maxn;++i)
    {
        ans+=dp_map[0][i][0];
    }
    ans+=dp_map[0][maxn][1];
    return ans;
}


int main()
{
    int n,m;

    while(cin>>n>>m)
    {
        if(n==0&&m==0)break;
        cout<<amount(m)-amount(n-1)<<endl;
    }

}
