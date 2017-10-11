#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
int main()
{
    int n;
    scanf("%d",&n);
    int mx = 1;
    for (int i=1; i<=n; i++)
    {
        int j = n-i;
        if (i >= j) break;
        if (gcd(i,j) == 1) mx = i;
    }
    printf("%d %d\n",mx,n-mx);
    return 0;
}
