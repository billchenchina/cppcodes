#include <iostream>
#include <set>
using namespace std;

set<int>dp(int n,int x)
{
    if(x==1)
    {
        set<int>s;
        s.insert(n);
        return s;
    }
    set<int>ans;
    int i=x;
    int num=0;
    do
    {
        num++;
    }
    while(i>>=1);
    ans.insert(1<<num);
    set<int>s=dp(n-1,x-(1<<num));
    ans.insert(s.begin(),s.end());
    return ans;
}

int main()
{
    int n,x;
    cin>>n>>x;
    set<int>ans=dp(n,x);
    for(auto i:ans)
    {
        cout<<i;
    }
}
