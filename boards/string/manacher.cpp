#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    int P[110010*2];
    while(cin>>str)
    {
    string str2="$#";
    int len=str.length();
    for(int i=0;i<len;++i)
    {
        str2.append(1,str[i]);
        str2.append("#");
    }
    len=str2.length();
    int maxn=0,id=0;
    int ans=0;
    memset(P,0,sizeof P);
    for(int i=1;i<len;++i)
    {
        if(maxn>i)
        {
            if(P[2*id-i]<maxn-i)
            {
                P[i]=P[2*id-i];
            }
            else
            {
                P[i]=maxn-i;
            }
        }
        else
        {
            P[i]=1;
        }
        while(str2[i+P[i]]==str2[i-P[i]])P[i]++;
        if(i+P[i]>maxn)
        {
            maxn=i+P[i];
            id=i;
        }
        if(P[i]>ans)ans=P[i];
    }
    cout<<ans-1<<endl;
    }
}
