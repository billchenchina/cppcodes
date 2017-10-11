#include <bits/stdc++.h>

using namespace std;


int gcd(int a,int b)
{
    if(a<b)swap(a,b);
    if(b==0)return a;
    return gcd(b,a%b);
}

int main()
{
    #define fin cin
    #define fout cout
    int N,K,id;
    fin>>N>>K>>id;
    if(K==0)
    {
        fout<<"0/1";
        return 0;
    }
    if(N==K)
    {
        fout<<"1/1";
        return 0;
    }
    if(N==2&&K==1)
    {
        fout<<"1/2";
        return 0;
    }
    if(K==N-1)
    {
        fout<<K<<'/'<<N;
        return 0;
    }
    if(N==3)
    {
        if(K==1)
        {
            fout<<"1/3";
            return 0;
        }
        if(K==2)
        {
            fout<<"2/3";
            return 0;
        }
    }
    else
    {
        fout<<K/gcd(N,K)<<'/'<<N/gcd(N,K);
    }


}
