#include <iostream>
#include <set>
using namespace std;
int main(){
    for(int i=102;i<=329;i++){
        set<int>s;
        int j=2*i,k=3*i;
        int tmp;
        for(int t=0;t<3;t++){
            tmp=(t==0?i:(t==1?j:k));
            if(s.find(tmp%10)!=s.end()||tmp%10==0)break;
            else s.insert(tmp%10);
            tmp/=10;
            if(s.find(tmp%10)!=s.end()||tmp%10==0)break;
            else s.insert(tmp%10);
            tmp/=10;
            if(s.find(tmp%10)!=s.end()||tmp%10==0)break;
            else s.insert(tmp%10);
        }
        if(s.size()==9){
            cout<<i<<' '<<j<<' '<<k<<endl;
        }
    }
}
