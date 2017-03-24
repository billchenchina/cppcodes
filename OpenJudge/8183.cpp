#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    int a,b,d;
    char c,e;
    e=' ';
    scanf("%d %d %c %d",&a,&b,&c,&d);
    if(d==0){
        for(int i=0;i<a;i++){
            for(int k=0;k<b;k++){
                if(i==0|i==a-1){
                    printf("%c",c);
                }
                else{
                    if(k==0 |   k==b-1){
                        printf("%c",c);
                    }
                    else{
                        printf("%c",e);
                    }
                }
            }
        cout<<endl;
        }
    }
    else{
        for(int i=0;i<a;i++){
            for(int k=0;k<b;k++){
                printf("%c",c);
            }
            cout<<endl;
        }
    }
    return 0;
}