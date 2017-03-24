#include<iostream>
#include<cstdio>
#include <cstring>
using namespace std;

int main() {
    char a[1000];
    cin>>a;
    int len=strlen(a),k=1;
    for(int i=0;i<len;i++){
        if(a[i]>='a'&&a[i]<='z'){
            a[i]=a[i]-'z'+'Z';
        }
    }
    cout<<"(";
     for(int i=1;i<len;i++){
        if(a[i]!=a[i-1]){
            k++;
         }
     }
     int j=0;
     for(int i=0;i<k;i++){
        int p=1;
        cout<<a[j]<<",";
        while(a[j]==a[j+1]){
            p++;
            j++;
         }
         j++;
         cout<<p<<")";
         if(i!=k-1){
            cout<<"(";
         }
     }
    return 0;
}