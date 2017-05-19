#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int main(){
    ifstream fin("pencil.in");
    ofstream fout("pencil.out");
    int pencil_num;
    fin>>pencil_num;
    vector<int>values(3,0);
    for(int i=0;i<3;i++){
        int num,amount;
        fin>>num>>amount;
        values[i]+=(pencil_num/num)*amount;
        if(pencil_num%num!=0)
            values[i]+=amount;
    }
    fout<<min(values[0],min(values[1],values[2]));


}
