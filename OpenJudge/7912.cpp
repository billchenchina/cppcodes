#include <iostream>
#include <cstdio>
#include <cstring> 
#include <cmath>
using namespace std;
int pd(int a) {
    if(a==0||a==1) {
        return 1;
    } else {
        int b=sqrt(a);
        for(int i=2; i<=b; i++) {  
            if(a%i==0&&a!=b) {
                return 1;
            }
        }
        return 0;
    }
}
int main() {
    char sentence[100];
    gets(sentence);
    int k,d,len=strlen(sentence),lena[26],max=0,min=100;
    for(int i=0;i<26;i++){
        lena[i]=0;
    }
    for(int i=0;i<len;i++){
        lena[sentence[i]-'a']++;
    }
    for(int i=0;i<26;i++){        
        if(lena[i]>max){
            max=lena[i];
        }
        if(lena[i]<min&&lena[i]!=0){
            min=lena[i];
        }
    }
    d=max-min;
    k=pd(d); 
    if(k==1){
        cout<<"No Answer"<<endl<<0;
    }else{
        cout<<"Lucky Word"<<endl<<d;
    }
    
    return 0;
}