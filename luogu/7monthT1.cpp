
#include <iostream>

using namespace std;
int a[100000];
int main(){
    int N,X;
    cin>>N>>X;
    long long eaten=0;
    cin>>a[0];
    if(a[0]>X){
        eaten+=a[0]-X;
        a[0]=X;
        //cout<<a[0]<<' ';
    }
    for(int i=1;i<N;i++){
        cin>>a[i];
        if(a[i-1]+a[i]>X){
            eaten+=a[i-1]+a[i]-X;
            a[i]=X-a[i-1];
        }
        //cout<<a[i]<<' ';


    }
    cout<<eaten;
}
