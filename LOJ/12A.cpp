#include <bits/stdc++.h>

using namespace std;



int main()
{
    string str;
    cin>>str;
    int k;
    cin>>k;
    bool is_ok=true;
    for(int i=1;i<str.size();++i)
    {
        if(str[i]!=str[i-1])
        {
            is_ok=false;
        }
    }
    if(k==1)
    {
        int bukkit[4];
        memset(bukkit,0,sizeof(bukkit));
        for(int i=0;i<str.size();++i)
        {
            if(str[i]=='A')bukkit[0]++;
            else if(str[i]=='T')bukkit[1]++;
            else if(str[i]=='G')bukkit[2]++;
            else if(str[i]=='C')bukkit[3]++;
        }
        cout<<max(max(bukkit[0],bukkit[1]),max(bukkit[2],bukkit[3]));
        return 0;
    }
    if(is_ok)
    {
        cout<<str.size();
        return 0;
    }
    int value_bukkit[16];
    memset(value_bukkit,0,sizeof(value_bukkit));
    map<string,int>m;
    for(int i=0;i+k<=str.size();++i)
    {
        string s=str.substr(i,k);
        m[s]++;
    }
    int max_value=0;
    string s2;
    for(map<string,int>::iterator iter=m.begin();iter!=m.end();++iter)
    {
        if(max_value<iter->second)
        {
            max_value=iter->second;
            s2=iter->first;
        }
    }
    cout<<max_value;
}
