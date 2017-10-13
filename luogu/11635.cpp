#include <bits/stdc++.h>

struct io
{
	char op[1 << 26] , * s;
	//数组大小即读入数据量大小
	io()
	{
		fread( s = op , 1 , 1 << 26 , stdin );
	}
	inline int nextInt()
	{
		register int u = 0;
		while( * s < 48 ) s++;
		while( * s > 32 )
			u = u * 10 + * s++ - 48;
		return u;
	}
};
io IOReader;
using namespace std;

int t;

int

int main()
{
    int n;
    cin>>n>>t;
    for(int i=0;i<n;++i)
    {
        int x,y,z;
        cin>>x>>y>>z;
        int a=1;

    }

}
