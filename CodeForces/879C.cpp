#include <bits/stdc++.h>

using namespace std;

int getbit(int x,int i)
{
    return (x>>i)&1;
}
void setbit_0(int &x,int i)
{
    if(getbit(x,i))
    {
        x=x-(1<<i);
    }
}
void setbit_1(int &x,int i)
{
    if(!getbit(x,i))
    {
        x=x+(1<<i);
    }
}
void setbit_xor(int &x,int i)
{
    if(getbit(x,i))
    {
        setbit_0(x,i);
    }
    else
    {
        setbit_1(x,i);
    }
}

int main()
{
    // For status type
    // 0 => 0
    // 1 => 1
    // 2 => x
    // 3 => !x
    int status[15];
    fill(status,status+15,2);
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        char opt;
        cin>>opt;
        int val;
        cin>>val;
        for(int i=0;i<15;++i)
        {
            switch(opt)
            {
            case '|':
                {
                    if(getbit(val,i)==1)
                    {
                        status[i]=1;
                    }
                    else
                    {
                        // Leave alone
                    }
                    break;
                }
            case '&':
                {
                    if(getbit(val,i)==1)
                    {
                        // Leave alone
                    }
                    else
                    {
                        status[i]=0;
                    }
                    break;
                }
            case '^':
                {
                    if(getbit(val,i)==1)
                    {
                        if(status[i]==0||status[i]==2)
                        {
                            status[i]++;
                        }
                        else
                        {
                            status[i]--;
                        }
                    }
                    else
                    {
                        // Leave alone
                    }
                }
            }
        }
    }
    vector<int>changes[4];
    for(int i=0;i<15;++i)
    {
        changes[status[i]].push_back(i);
    }
    cout<<3<<endl;
    int and_val=0;
    for(int i=0;i<changes[0].size();++i)
    {
        setbit_0(and_val,changes[0][i]);
    }
    cout<<"& "<<and_val<<endl;
    int or_val=0;
    for(int i=0;i<changes[1].size();++i)
    {
        setbit_1(or_val,changes[1][i]);
    }
    cout<<"| "<<or_val<<endl;
    int xor_val=0;
    for(int i=0;i<changes[3].size();++i)
    {
        setbit_xor(xor_val,changes[3][i]);
    }
    cout<<"^ "<<xor_val<<endl;

}
