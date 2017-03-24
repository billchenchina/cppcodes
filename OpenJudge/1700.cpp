#include <cstdio>
#include <iostream>
using namespace std;
int mapx[9][9];
int ttl=1;
bool lie[9],zuox[30],youx[30];
void print() {
    cout<<"No. "<<ttl++<<endl;
    for(int i=1; i<=8; i++) {
        for(int k=1; k<=8; k++) {
            cout<<mapx[k][i]<<" ";
        }
        cout<<endl;
    }

}
void srch(int line) {
    for(int i=1; i<=8; i++) {
        if(!(lie[i]||zuox[line+i]||youx[i-line+7])) {
            lie[i]=1;            zuox[line+i]=1;            youx[i-line+7]=1;            mapx[line][i]=1;
            if(line==8) print();
            else srch(line+1);
            lie[i]=0;            mapx[line][i]=0;            zuox[line+i]=0;            youx[i-line+7]=0;
        }
    }


}
int main() {
    srch(1);
    return 0;
}