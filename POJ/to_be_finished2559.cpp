#include <stack>
#include <iostream>
#include <vector>

using namespace std;

struct mypair
{
    int length;
    int width;
    mypair() {}
    mypair(int _length,int _width)
    {
        length=_length;
        width=_width;
    }
};
typedef mypair pint;
int main()
{
    ios::sync_with_stdio(false);
    int n;
    while(cin>>n&&n!=0)
    {
        stack<pint>st;
        vector<int>v(n+1);
        for(int i=1; i<=n; ++i)
        {
            cin>>v[i];
        }
        int maxarea=v[1];
        for(int i=1; i<=n; ++i)
        {

            st.push(pint(v[i],i));
            maxarea=max(maxarea,st.top().length*st.top().width);
        }
        cout<<maxarea<<endl;
    }

}
