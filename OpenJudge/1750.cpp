#include <cstdio>
#include <iostream>
#include <cstring> 
using namespace std;
int len;
char a[7],b[7];
bool a1[7];

void zhixing(int i){
    for(int k=0;k<len;k++){
        if(!a1[k]){
            a1[k]=1;
            b[i]=a[k];
            if(i!=len-1)    zhixing(i+1);
            else cout<<b<<endl;
            a1[k]=0;
        }
    }
}
int main(){
    cin>>a;
    len=strlen(a);
    zhixing(0);
    return 0;
}