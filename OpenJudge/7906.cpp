#include <iostream>
#include <cstring> 
#include <string>
using namespace std;
int main()
{
	int a,b[101],c[101],d[101],e[101],answer=0,maxn=0,k=0; 
	string f[101],name;
	string x[101],y[101];
	cin >> a;
	for (int i=1;i<=a;i++)
	{
		cin >> f[i] >> b[i] >> c[i] >> x[i] >> y[i] >> e[i] ; 
	}
	for (int i=1;i<=a;i++)
	{
		answer = 0;
		if((b[i] > 80) && (e[i] >= 1))
		answer+=8000;
		if ((b[i] > 85) && (c[i] > 80))
		answer+=4000;
		if (b[i] > 90)
		answer+=2000;
		if ((b[i] > 85) && (y[i] == "Y"))
		answer+=1000;
		if ((c[i] > 80) && (x[i] == "Y"))
		answer+=850;
		k+=answer;
		if (maxn < answer)
		{name=f[i];
		maxn = answer ;
	}
	}
	cout << name << endl << maxn << endl << k;
	return 0;
} 
