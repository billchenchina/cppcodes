#include<iostream>
#include<cstdio>
using namespace std;

int main() {
    int k,a,c1,c5,c10;
    c1=0;
    c5=0;
    c10=0;
    cin>>k;
    for(int i=0;i<k;i++){
        cin>>a;
        if(a==1){
            c1++;
        }
        else if(a==5){
            c5++;
        }
        else if(a==10){
            c10++;
        }
        else{
            a=a;
        }
    }
    printf("%d\n%d\n%d",c1,c5,c10);
    return 0;
}