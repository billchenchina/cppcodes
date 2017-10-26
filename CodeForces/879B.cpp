#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    long long k;
    cin>>n>>k;
    vector<int>vec(n);
    int maxn=INT_MIN;
    for(int i=0;i<n;++i)
    {
        cin>>vec[i];
        if(vec[i]>maxn)
        {
            maxn=vec[i];
        }
    }
    if(k>1000)
    {
        cout<<maxn;
        return 0;
    }
    deque<int>dq;
    for(int i=0;i<n;++i)
    {
        dq.push_back(vec[i]);
    }

    int front=vec[0];
    int times=-1;
    for(;;)
    {
        long long p1,p2;
        p1=dq.front();
        dq.pop_front();
        p2=dq.front();
        dq.pop_front();
        int win=p1>p2?p1:p2;
        int lose=p1>p2?p2:p1;
        if(win==front&&times==-1)
        {
            times=1;
        }
        else if(win==front)
        {
            times++;
        }
        else
        {
            times=1;
            front=win;
        }
        if(times==k)
        {
            cout<<front;
            return 0;
        }
        dq.push_front(win);
        dq.push_back(lose);
    }

}
