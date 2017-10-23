#include <bits/stdc++.h>
  
using namespace std;
  
bool ok(int i,int k)
{
    int a=i/100;
    int b=(i/10)%1000;
    int c=i%1000;
    if(a%k==0
       &&b%k==0
       &&c%k==0)
    {
        return true;
    }
    return false;
}
  
int main()
{
    int k;
    cin>>k;
    bool flag=0;
    for(int i=10000;i<=30000;++i)
    {
        if(ok(i,k))
        {
            cout<<i<<endl;
            flag=true;
        }
    }
    if(!flag)
    {
        cout<<"No";
    }
}
