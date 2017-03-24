#include <iostream>
#include <cstdio>
#include <cstring>
#include <memory>
using namespace std;
char sen[20000],dc[200][100],maxdc[100],mindc[100];
int d=1,senlen,len[200],maxlen,minlen;

int main() {
    maxlen=0;
    minlen=102;
    gets(sen);
    senlen=strlen(sen);
    for(int i=0; i<senlen; i++) {
        if(sen[i]==' ') {
            d++;
        }
    }
    int k=0;
    for(int i=0; i<d; i++) {
        int p=0;
        while(sen[k]!=' ') {
            if(k==senlen){
                break;
            }
            dc[i][p]=sen[k];
            k++;
            p++;
        }
        k++;
        if(strlen(dc[i])>maxlen) {
            maxlen=strlen(dc[i]);
            for(int q=0; q<strlen(dc[i]); q++) {
                maxdc[q]=dc[i][q];
            }
        }
        if(strlen(dc[i])<minlen) {
            minlen=strlen(dc[i]);
            memset(mindc,0,100);
            for(int q=0; q<strlen(dc[i]); q++) {
                mindc[q]=dc[i][q];
            }
        }
    }
    cout<<maxdc<<endl<<mindc;


    return 0;
}