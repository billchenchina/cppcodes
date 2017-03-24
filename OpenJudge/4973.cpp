#include <cstdio>
#include <iostream>
using namespace std;
int s[2][100000000];
int main() {
    int n,na,nb,a[100],b[100],ak=0,bk=0;
    cin>>n>>na>>nb;
    for(int i=0;i<na;i++){
        cin>>a[i];
    }
    for(int i=0;i<nb;i++){
        cin>>b[i];
    }
    for(int i=0;i<n;i++){
        if(a[i%na]==0){
            if(b[i%nb]==2){
                ak++;
            }else if(b[i%nb]==5){
                bk++;
            }
        }
        else if(a[i%na]==2){
            if(b[i%nb]==0){
                bk++;
            }else if(b[i%nb]==5){
                ak++;
            }
        }
        else{
            if(b[i%nb]==0){
                ak++;
            }
            else if(b[i%nb]==2){
                bk++;
            }
        }
        
        
    }
    if(ak<bk){
        cout<<"B";
    }else if(ak>bk){
        cout<<"A";
    }else{
        cout<<"draw";
    }
    return 0;
}
