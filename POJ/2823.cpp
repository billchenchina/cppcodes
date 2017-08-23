#include <deque>
#include <iostream>
#include <vector>

using namespace std;

struct mypair
{
    int position;
    int value;
    mypair(){}
    mypair(int _position,int _value)
    {
        position=_position;
        value=_value;
    }
};
typedef mypair pint;
int main()
{
    ios::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    // min_deque
    // from small to big
    deque<pint>queue1,queue2;
    vector<int>v(n+1);
    for(int i=1; i<=n; ++i)
    {
        cin>>v[i];
    }

    for(int i=1; i<k; ++i)
    {
        while(queue1.size()>0&&(queue1.end()-1)->value>=v[i])
        {
            queue1.pop_back();
        }
        queue1.push_back(pint(i,v[i]));
    }
    for(int i=k; i<=n; ++i)
    {
        while(queue1.size()>0&&(queue1.end()-1)->value>=v[i])
        {
            queue1.pop_back();
        }
        queue1.push_back(pint(i,v[i]));
        while(queue1.front().position+k<=i)
        {
            queue1.pop_front();
        }

        cout<<queue1.front().value<<' ';
    }
    cout<<endl;
    for(int i=1; i<k; ++i)
    {
        while(queue2.size()>0&&(queue2.end()-1)->value<=v[i])
        {
            queue2.pop_back();
        }
        queue2.push_back(pint(i,v[i]));
    }
    for(int i=k; i<=n; ++i)
    {
        while(queue2.size()>0&&(queue2.end()-1)->value<=v[i])
        {
            queue2.pop_back();
        }
        queue2.push_back(pint(i,v[i]));
        while(queue2.front().position+k<=i)
        {
            queue2.pop_front();
        }

        cout<<queue2.front().value<<' ';
    }
}
