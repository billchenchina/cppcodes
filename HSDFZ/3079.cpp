#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    int yy=0,sz=0,kg=0,oth=0,len;
    char a[100000];
    gets(a);
    len=strlen(a);
    for(int i=0;i<len;i++){
        if((a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z')){
            yy++;
        }else if(a[i]>='0'&&a[i]<='9'){
            sz++;
        }else if(a[i]==' '){
            kg++;
        }else oth++;
    }
    printf("%d %d %d %d",yy,sz,kg,oth);
    return 0;
}
