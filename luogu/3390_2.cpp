#include <bits/stdc++.h>

#ifndef MODNUM
#define MODNUM 1000000007
#endif
namespace BCC
{
class matrix
{
public:
    int _n;
    int _m;
    std::vector<std::vector<long long > > _matrix_array;
    /*
    matrix()
    {
        _n=2;
        _m=2;
        _matrix_array.resize(2,std::vector<long long>(2,0));
    }
    matrix(int n,int m)
    {
        _n=n;
        _m=m;
        _matrix_array.resize(n,std::vector<long long>(m,0));
    }
    */
};

class square_matrix : public matrix
{
public:
    square_matrix()
    {
        matrix::_matrix_array.resize(2,std::vector<long long>(2,0));
    }
    square_matrix(int n)
    {
        matrix::_n=n;
        matrix::_m=n;
        matrix::_matrix_array.resize(n,std::vector<long long>(n,0));
    }
    friend square_matrix operator *(const square_matrix & sm1,const square_matrix & sm2)
    {
        if(sm1._n!=sm2._n)
        {
            throw "Not a equal length matrix";
        }
        else
        {
        	square_matrix sm(sm1._n);
        	for(int i=0;i<sm1._n;++i)
        	{
        		for(int j=0;j<sm1._n;++j)
        		{
        			for(int k=0;k<sm1._n;++k)
        			{
        				sm._matrix_array[i][j]+=(sm1._matrix_array[i][k]*sm2._matrix_array[k][j])%MODNUM;
        				sm._matrix_array[i][j]%=MODNUM;
        			}
        		}
        	}
            return sm;
        }
    }
};



template <typename T>
T fast_pow(T down,long long n)
{
	if(n==1)
	{
		return down;
	}
	T ret=fast_pow(down,n/2);
	ret=ret*ret;
	if(n%2==1)
	{
		ret=down*ret;
	}
	return ret;
}

}
int main ()
{
    long long n,k;
    std::cin>>n>>k;
    BCC::square_matrix sm(n);
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            std::cin>>sm._matrix_array[i][j];
        }
    }
    sm=fast_pow(sm,k);
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            std::cout<<sm._matrix_array[i][j]<<' ';
        }
        std::cout<<std::endl;
    }
}
