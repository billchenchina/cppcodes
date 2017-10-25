#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    string str;
    cin>>str;
    bool have[26]= {0};
    int maxn=0;
    int lastpos=0;
    for(int i=0; i<n; ++i)
    {
        if(str[i]>='A'&&str[i]<='Z')
        {
            int cnt=0;
            for(int j=0; j<26; ++j)
            {
                if(have[j])
                    cnt++;
            }
            maxn=maxn>cnt?maxn:cnt;
            memset(have,0,sizeof(have));
            lastpos=i+1;
        }
        else
        {
            have[str[i]-'a']=true;
        }
    }
    int cnt=0;
    for(int j=0; j<26; ++j)
    {
        if(have[j])
            cnt++;
    }
    maxn=maxn>cnt?maxn:cnt;
    cout<<maxn;
}
