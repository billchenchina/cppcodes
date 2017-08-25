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
        vector<long long>v(n+2);
        for(int i=1; i<=n; ++i)
        {
            cin>>v[i];
        }
        long long maxarea=-1;
        v[n+1]=0;
        for(int i=1; i<=n+1; ++i)
        {

            if(st.empty())
            {
                st.push(mypair(v[i],1));
            }
            else
            {
                if(v[i]>st.top().length)
                {
                    st.push(mypair(v[i],1));
                }
                else
                {
                    long long width=0;

                    while(!st.empty()&&st.top().length>=v[i])
                    {
                        width+=st.top().width;
                        if(width*st.top().length>maxarea)
                        {
                            maxarea=width*st.top().length;
                        }
                        st.pop();
                    }
                    st.push(mypair(v[i],width+1));
                }
            }
        }
        cout<<maxarea<<endl;
    }

}
