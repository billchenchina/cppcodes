#include <bits/stdc++.h>


namespace BCC
{
class matrix
{
public:
    int _n;
    int _m;
    std::vector<std::vector<long long > > _matrix_array;
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

    }
};



template <typename T>
void fast_pow(T down,long long n)
{

}

}
int main ()
{
    BCC::square_matrix sm(2);
}
