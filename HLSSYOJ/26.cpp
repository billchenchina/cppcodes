#include <bits/stdc++.h>
#define MODNUM static_cast<long long>(1e9+7)
using namespace std;
long long n;

struct matrix
{
    vector<vector<long long> >v;
    matrix()
    {
        v.resize(n,vector<long long>(n,0));
    }
    matrix(const vector<vector<long long> > &_v)
    {
        v.resize(n,vector<long long>(n,0));
        for(long long i=0; i<n; ++i)
        {
            for(long long j=0; j<n; ++j)
            {
                v[i][j]=_v[i][j];

            }
        }
    }
    matrix operator *(const matrix &j2)const
    {
        vector<vector<long long> >ansv(n,vector<long long>(n,0));
        for(long long i=0; i<n; ++i)
        {
            for(long long j=0; j<n; ++j)
            {
                for(long long k=0; k<n; ++k)
                {
                    ansv[i][j]+=(this->v[i][k]*j2.v[k][j])%MODNUM;
                    ansv[i][j]%=MODNUM;
                }
            }
        }
        matrix ret(ansv);
        return ret;
    }
    matrix &operator=(const matrix &m)
    {
        v=m.v;
    }
    void output()
    {
        for(long long i=0; i<n; ++i)
        {
            for(long long j=0; j<n; ++j)
            {
                cout<<v[i][j]<<' ';
            }
            cout<<endl;
        }
    }
    void input()
    {
        for(long long i=0; i<n; ++i)
        {
            for(long long j=0; j<n; ++j)
            {
                cin>>v[i][j];
            }
        }
    }

};

matrix power(matrix m,long long a)
{
    if(a==1)
    {
        return m;
    }
    matrix m2=power(m,a/2);
    m2=m2*m2;
    if(a&1)
    {
        m2=m2*m;
    }
    return m2;
}

int main()
{
    long long k;
    cin>>n>>k;
    vector<vector<long long> >v(n,vector<long long>(n));
    for(long long i=0; i<n; ++i)
    {
        for(long long j=0; j<n; ++j)
        {
            cin>>v[i][j];
            v[i][j]%=MODNUM;
        }
    }
    matrix jz1(v);
    jz1=power(jz1,k);
    jz1.output();
}
