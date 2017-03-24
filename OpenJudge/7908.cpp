#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
struct student {
    int xuehao;
    int yuwen;
    int shuxue;
    int yingyu;
    int ttl;
} students[300];
bool op(student a,student b) {
    if(a.ttl>b.ttl){
        return false;
    }if(a.ttl<b.ttl){
        return true;
    }if(a.yuwen>b.yuwen){
        return false;
    }if(a.yuwen<b.yuwen){
        return true;
    }if(a.xuehao<b.xuehao){
        return false;
    }
    return true;
    
}
int main() {
    int n;
    cin>>n;
    for(int i=0; i<n; i++) {
        students[i].xuehao=i+1;
        cin>>students[i].yuwen>>students[i].shuxue>>students[i].yingyu;
        students[i].ttl=students[i].yuwen+students[i].shuxue+students[i].yingyu;
    }
    sort(students,students+n,op); 
    for(int i=n-1;i>n-6;i--){
        cout<<students[i].xuehao<<" "<<students[i].ttl<<endl; 
    }
    return 0;
}