/*
 *Unfinished
**/
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;
int monthHas31Days[]= {1,3,5,7,8,10,12};
int monthHas30Days[]= {4,6,9,11};
bool isGreatYear(int year) {
    if(year%4==0&&year%100!=0)return true;
    if(year%400==0)return true;
    return false;
}
struct date {
    unsigned short year;
    unsigned short month;
    unsigned short day;
    bool operator!=(date d){
        if(year==d.year&&month==d.month&&day==d.day)return false;
        return true;
    }
    date operator+(int noneofuse) {
        date s=*this;
        s.day++;
        for(int i=0; i<7; i++) {
            if(s.day==31&&s.month==monthHas31Days[i]) {
                s.month++;
                s.day=1;
            }
        }
        for(int i=0; i<4; i++) {
            if(s.day==30&&s.month==monthHas30Days[i]) {
                s.month++;
                s.day=1;
            }
        }
        if(s.month==2) {
            if(isGreatYear(s.year)) {
                if(s.day==30) {
                    s.month++;
                    s.day=1;
                }
            } else {
                if(s.day==29) {
                    s.month++;
                    s.day=1;
                }
            }
        }
        if(s.month==13) {
            s.year++;
            s.month=1;
        }
        return s;
    }
    date(int datenum) {
        this->day=datenum%100;
        datenum/=100;
        this->month=datenum%100;
        datenum/=100;
        this->year=datenum;
    }
    string getdate() {
        stringstream ss("");
        ss<<year;
        ss<<setfill('0')<<setw(2)<<month;
        ss<<setfill('0')<<setw(2)<<day;
        string str;
        ss>>str;
        return str;
    }
};
int main() {
    int rslt=0;
    int from,to;
    cin>>from>>to;
    date startd(from),endd(to);
    endd=endd+1;
    for(;startd!=endd;startd=startd+1){
        string tmp=startd.getdate(),tmp2;
        tmp.reserve();
        if(tmp2==tmp){
                rslt++;
        }
    }
    cout<<rslt;
}
