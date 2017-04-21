#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;//why wrong?
/*
5 3
1001 90
1002 100
1003 89
1004 96
1005 99
*/
class stu
{
public:
    int xuehao;
    float chengji;
    bool operator < (const stu  &s2) const;
};

bool stu::operator < (const stu &s2) const
{
    if(chengji!=s2.chengji)
        return this->chengji > s2.chengji;
}
stu stus[100];
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=0; i<n; i++)
    {
        cin>>stus[i].xuehao>>stus[i].chengji;
    }
    sort(stus,stus+n);
    for(int i=0; i<n; i++)
    {
        cout<<stus[i].xuehao<<"\t"<<stus[i].chengji<<endl;
    }
    cout<<stus[k-1].xuehao<<' '<<stus[k-1].chengji;
    return 0;
}
