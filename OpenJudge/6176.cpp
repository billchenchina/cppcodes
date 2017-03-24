#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
class stu {
    public:
        int xuehao;
        float chengji;
};
bool cmp(const stu &s1,const stu &s2){
    if(s1.chengji>s2.chengji)return 1;
    return 0;
}
stu stus[100];
int main() {
    int n,k;
    cin>>n>>k;
    for(int i=0; i<n; i++) {
        cin>>stus[i].xuehao>>stus[i].chengji;
    }
    sort(stus,stus+n,cmp);
    cout<<stus[k-1].xuehao<<' '<<stus[k-1].chengji;
    return 0;
}
