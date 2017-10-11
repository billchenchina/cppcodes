#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin>>T;
    // 0 for lose
    // 1 for win
    bool i=0;
    {
        int a;
        cin>>a;
        if(a&1)
        {
            i=0;
            cout<<"NIE"<<endl;
        }
        else
        {
            i=1;
            cout<<"TAK"<<endl;
        }
        T--;
    }
    while(T--)
    {
        int a;
        cin>>a;
        bool b=(a+1)&1;
        i=i^b;
        if(i)
        {
            cout<<"TAK"<<endl;
        }
        else
        {
            cout<<"NIE"<<endl;
        }
    }
}

// 1 0  => lose
// 2 1  => win
// 3 0  => win
// 4 1  => lose
// 5 0  => lose
// 6 1  => win
// 7 0  => win
// 8 1  => lose
// 9 0  => lose
// 10 1 => win
// 11 0 => win
