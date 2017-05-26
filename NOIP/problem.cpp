#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t,k;
    cin>>t>>k;
    vector<vector<int> >YHTriangle(2001,vector<int>(2001,1));
    for(int i=0;i<=2000;i++){
        YHTriangle[1][i]=i%k;
        if(i>=2){
            for(int m=2;m<i;m++){
                YHTriangle[m][i]=(YHTriangle[m-1][i-1]+YHTriangle[m][i-1])%k;
            }
        }
    }
    while(t--){
        int n,m;
        int ttl=0;
        cin>>n>>m;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=min(i,m);j++){
                if(YHTriangle[j][i]==0){
                    ttl++;
                }
            }
        }
        cout<<ttl<<endl;
    }
}
