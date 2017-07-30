/**
  * Posted on 17/07/30
  * 啊 好久没做这种水题了
  * 好久没上 OpenJudge 现在再上 OpenJudge 感觉好亲切啊
  * 最近状态一直不太好，经常全场爆零？？？
  * 总之 加油吧 NOIP2017 rp++ 
  * Bless All.
  * 
  **/



#include <bits/stdc++.h>
using namespace std;

class student {
public:

    string name;
    int month;
    int day;
    bool operator <(const student &s)const {
        if(month<s.month)return true;
        if(month>s.month)return false;
        if(day<s.day)return true;
        if(day>s.day)return false;
        if(name.length()<s.name.length())return true;
        if(name.length()>s.name.length())return false;
        return name<s.name;
    }
    bool operator==(const student&s)const {
        return (month==s.month)&&(day==s.day);
    }

};
void output(const vector<student>stuList,
            int &i,const int N,bool &flag);


int main() {
    int n;
    cin>>n;
    vector<student>stuList(n);
    for(int i=0; i<n; i++) {
        cin>>stuList[i].name>>stuList[i].month>>stuList[i].day;
    }
    sort(stuList.begin(),stuList.end());
    int i=0;
    bool flag=0;
    output(stuList,i,n,flag);
    if(flag==0)cout<<"None";
    return 0;
}

void output(const vector<student>stuList,
            int &i,const int N,bool &flag) {
    while(i<N) {
        if(stuList[i]==stuList[i+1]) {
            cout<<stuList[i].month<<' '<<stuList[i].day
                <<' ';
            flag=1;
            while(stuList[i]==stuList[i+1]) {
                cout<<stuList[i].name<<' ';
                i++;
            }
            cout<<stuList[i].name<<endl;
            i++;
        } else
            i++;
    }
}
