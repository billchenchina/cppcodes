#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main() {
    char a[100],c[100];
    gets(a);
    int b=strlen(a),d=0;
    for(int i=0;i<b;i++){
        c[i]=a[b-i-1];
    }
    for(int i=0;i<0.5*b;i++){
        if(a[i]!=c[i]){
            d++;
        }
    }
    if(d==0){
        cout<<"yes";
    }else{
        cout<<"no";
    }
    return 0;
}