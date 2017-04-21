#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int person_num,cake_num;
struct cake
{
    int r;
    double s;

} cakes[10001];
istream & operator>>(istream &in,cake & c)
{
    int tmp;
    in>>tmp;
    c.r=tmp;
    c.s=M_PI*tmp*tmp;
}
bool pd(double mid)
{
    int sum=0;
    for(int i=0; i<cake_num; i++)
    {
        sum+=int(cakes[i].s/mid);
    }
    return sum>=person_num;

}
int main()
{
    double l=0,r=0,mid;
    cin>>cake_num>>person_num;
    person_num++;
    for(int i=0; i<cake_num; i++)
    {
        cin>>cakes[i];
        if(cakes[i].r>r)r=cakes[i].s;
    }
//
    do
    {
        mid=l+(r-l)/2;
        if(pd(mid))
        {
            l=mid;
        }
        else
        {
            r=mid;
        }

    }
    while(r-l>0.00001);
    printf("%.3lf",l);

    return 0;

}
