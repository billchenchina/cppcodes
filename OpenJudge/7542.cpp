#include<iostream>
#include<cstdio>
using namespace std;

int main() {
    int n,a,b,mm=-1,max=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        if(a>=90&&a<=140&&b>=60&&b<=90){
            max++;
            if(max>mm){
                mm=max;
            }
        }
        else{
            max=0;
        }
    }
    cout<<mm;
    return 0;
}