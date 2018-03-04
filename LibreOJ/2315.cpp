#include <fstream>
#include <cstring>
#include <iostream>
#include <stack>

using namespace std;



inline void read_until_eoln()
{
    char a;
    do
    {
        a=cin.get();
    }
    while(a!='\n');
}

int to_int(const string &s)
{
    int ans=0;
    for(int i=0; i<s.size(); ++i)
    {
        ans=ans*10+s[i]-'0';
    }
    return ans;
}


int main()
{
    int t;
    cin>>t;
    read_until_eoln();
    while(t--)
    {
        int L;
        cin>>L;
        string s;
        cin>>s;
        s=s.substr(2,s.size()-3);
        // O(1) 4 2~2
        read_until_eoln();
        bool vis[26];
        memset(vis,0,sizeof vis);
        bool error_status=false;
        stack<char>sta;
        stack<char>cant_enter_lib;
        stack<char>counted;
        int maxans=0;
        int a=0;
        for(int i=0; i<L; ++i)
        {
            char opt;
            cin>>opt;
            if(opt=='F')
            {
                char var;
                cin>>var;
                if(vis[var-'a'])
                {
                    error_status=true;
                }
                else
                {
                    vis[var-'a']=true;
                    sta.push(var);
                }
                string s1,s2;
                cin>>s1>>s2;
                if(isdigit(s2[0])&&isdigit(s1[0]))
                {
                    if(to_int(s1)>to_int(s2))
                    {
                        cant_enter_lib.push(var);
                    }
                }
                else if(s1=="n"&&s2=="n")
                {

                }
                else
                {
                    if(isdigit(s1[0])&&s2=="n"&&cant_enter_lib.size()==0)
                    {
                        a++;
                        if(a>maxans)
                        {
                            maxans=a;
                        }
                        counted.push(var);
                    }
                    else
                    {
                        cant_enter_lib.push(var);
                    }
                }

            }
            else
            {
                if(!sta.empty())
                {
                    char c=sta.top();
                    sta.pop();
                    vis[c-'a']=false;
                    if((!counted.empty())&&counted.top()==c)
                        {a--;counted.pop();}
                    if((!cant_enter_lib.empty())&&c==cant_enter_lib.top())
                    {
                        cant_enter_lib.pop();
                    }
                }
                else
                {
                    error_status=true;
                }
            }
            read_until_eoln();
        }
        if(!sta.empty())
        {
            error_status=true;
        }
        if(error_status)
        {
            cout<<"ERR"<<endl;
            continue;
        }
        if(s[0]!='n')
        {
            if(maxans==0)
            {
                cout<<"Yes"<<endl;
            }
            else
            {
                cout<<"No"<<endl;
                //cout<<"Preferred "<<maxans<<endl;
            }
        }
        else
        {
            s=s.substr(2,s.size()-2);
            int a_=to_int(s);
            if(a_==maxans)
            {
                cout<<"Yes"<<endl;
            }
            else
            {
                cout<<"No"<<endl;
                //cout<<"Preferred "<<maxans<<" Output is "<<a_<<endl;
            }
        }
    }
}
