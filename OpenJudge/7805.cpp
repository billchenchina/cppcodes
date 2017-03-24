#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main() {
    char a[255],b[255];
    int c;
    gets(a);
    c=strlen(a);
    for(int i=0;i<c;i++){
        if(a[i]=='A'){
            b[i]='T';
        }
        else if(a[i]=='T'){
            b[i]='A'; 
        }
        else if(a[i]=='G'){
            b[i]='C';
        }
        else if(a[i]=='C'){
            b[i]='G';
        }
        cout<<b[i];
    }
    return 0;
}