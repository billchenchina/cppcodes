/*
 *
 * Accepted
**/
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int pencil_num;
    cin>>pencil_num;
    vector<int>values(3,0);
    for(int i=0;i<3;i++){
        int num,amount;
        cin>>num>>amount;
        values[i]+=(pencil_num/num)*amount;
        if(pencil_num%num!=0)
            values[i]+=amount;
    }
    cout<<min(values[0],min(values[1],values[2]));


}
