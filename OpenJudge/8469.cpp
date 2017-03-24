#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int len;
char a[31];
int yuan[33],jieg[33],act[33];
int main() {
    int flag1=0,flag2=0;
    gets(a);
    len=strlen(a);
    int ttl1=0,ttl2=1;
    for(int i=1; i<=len; i++) {
        yuan[i]=a[i-1]-'0';
    }
    gets(a);
    for(int i=1; i<=len; i++) {
        jieg[i]=a[i-1]-'0';
    }
    act[1]=0;
    for(int i=2; i<=len; i++) {
        if(act[i-2]==act[i-1]) { //do if act[i-1]==0
            if(yuan[i-1]==jieg[i-1])continue;
            else {
                act[i]=1;
                ttl1++;
                continue;
            }
        } else {
            if(yuan[i-1]!=jieg[i-1])continue;
            else {
                act[i]=1;
                ttl1++;
                continue;
            }
        }

    }
    if(yuan[len]==jieg[len]&&act[len]==act[len-1]) {
        flag1=1;
    } else if(yuan[len]!=jieg[len]&&act[len]!=act[len-1]) {
        flag1=1;
    }
    memset(act,0,sizeof(act));
    act[1]=1;
    for(int i=2; i<=len; i++) {
        if(act[i-2]==act[i-1]) { //do if act[i-1]==0
            if(yuan[i-1]==jieg[i-1])continue;
            else {
                act[i]=1;
                ttl2++;
                continue;
            }
        } else {
            if(yuan[i-1]!=jieg[i-1])continue;
            else {
                act[i]=1;
                ttl2++;
                continue;
            }
        }
    }
    if(yuan[len]==jieg[len]&&act[len]==act[len-1]) {
        flag2=1;
    } else if(yuan[len]!=jieg[len]&&act[len]!=act[len-1]) {
        flag2=1;
    }
    if(flag1==0&&flag2==0){cout<<"impossible";return 0;}
    if(flag1==0)ttl1=100;
    if(flag2==0)ttl2=100;
    cout<<int(ttl1<ttl2?ttl1:ttl2);

    return 0;
}