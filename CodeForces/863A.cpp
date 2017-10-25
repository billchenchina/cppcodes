#include <bits/stdc++.h>

using namespace std;

int main()
{
    char num[20];
    cin>>num;
    int len=strlen(num);
    int start_=0;
    int end_;
    for(end_=len-1;end_>=0;--end_)
    {
        if(num[end_]!='0')
        {
            break;
        }
    }
    if(end_==-1)
    {
        cout<<"YES";
        return 0;
    }
    if(end_==0)
    {
        cout<<"YES";
        return 0;
    }
    bool flag=0;
    for(int i=0;i<end_-start_;++i)
    {
        if(num[start_+i]!=num[end_-i])
        {
            flag=1;
        }
    }
    if(flag)
    {
        cout<<"NO";
    }
    else
    {
        cout<<"YES";
    }

}
