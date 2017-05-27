/*
 *Unfinished
**/
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
using namespace std;
int monthHas31Days[]= {1,3,5,7,8,10,12};
int monthHas30Days[]= {4,6,9,11};
bool isGreatYear(int year) {
    if(year%4==0&&year%100!=0)return true;
    if(year%400==0)return true;
    return false;
}
struct date {
    int year;
    int month;
    int day;
    bool operator!=(date d){
        if(year==d.year&&month==d.month&&day==d.day)return false;
        return true;
    }
    date operator++(int z) {
        this->day++;
        for(int i=0; i<7; i++) {
            if(this->day==32&&this->month==monthHas31Days[i]) {
                this->month++;
                this->day=1;
            }
        }
        for(int i=0; i<4; i++) {
            if(this->day==31&&this->month==monthHas30Days[i]) {
                this->month++;
                this->day=1;
            }
        }
        if(this->month==2) {
            if(isGreatYear(this->year)) {
                if(this->day==30) {
                    this->month++;
                    this->day=1;
                }
            } else {
                if(this->day==29) {
                    this->month++;
                    this->day=1;
                }
            }
        }
        if(this->month==13) {
            this->year++;
            this->month=1;
        }
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
    endd++;
    for(;startd.getdate()!=endd.getdate();startd++){
        string tmp=startd.getdate(),tmp2;
        tmp2=tmp;
        reverse(tmp.begin(),tmp.end());
        if(tmp2==tmp){
            rslt++;
        }
    }
    cout<<rslt;
}
