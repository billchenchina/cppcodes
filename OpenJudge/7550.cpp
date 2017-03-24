#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main() {
    int n,l;
    char a[20];
    cin>>n;
    for(int i=0; i<n; i++) {
        scanf("%s",a);
        l=strlen(a);
        if(a[0]>='a'&&a[0]<='z') {
            a[0]=a[0]-'a'+'A';
        }
        printf("%c",a[0]);
        for(int k=1; k<l; k++) {
            if(a[k]>='A'&&a[k]<='Z') {
                a[k]=a[k]-'A'+'a';
            }
            printf("%c",a[k]);  
        }
        if(i!=n-1)cout<<endl;
    }
    return 0;
}