#include <bits/stdc++.h>
  
using namespace std;
  
long long nextLong()
{
    long long ret=0;
    char a;
    a=getchar();
    while(!isdigit(a))
    {
        a=getchar();
    }
    while(isdigit(a))
    {
        ret=ret*10+a-'0';
        a=getchar();
    }
    return ret;
}
  
long long A[10+int(1e6)];
  
int main()
{
    long long N,K;
    N=nextLong();
    K=nextLong();
    for(long long i=0;i<N;++i)
    {
        A[i]=nextLong();
    }
    int L=0,R=K+1;
    for(long long i=0;i<N;++i)
    {
        while(i>R-1)
        {
            L++;
            R++;
        }
        while(R<N&&A[R]-A[i]<A[i]-A[L])
        {
            L++;
            R++;
        }
        if(A[R-1]-A[i]>A[i]-A[L])
        {
            cout<<A[R-1]<<' ';
        }
        else
        {
            cout<<A[L]<<' ';
        }
    }
}