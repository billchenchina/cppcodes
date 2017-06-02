#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>itemValue;
    itemValue.push_back(0);
    vector<int>number(n+1,0);
    vector<int>a(n+1);
    vector<int>b(n+1);
    vector<int>c(n+1);
    vector<int>d(n+1);

    for(int i=0;i<m;i++){
        int tmp;
        cin>>tmp;
        itemValue.push_back(tmp);
        number[tmp]++;
    }
    for(int i=1;9*i<n;i++){//i=>(D-C)


        int x=9*i+1,s=0;//x=>min(D-A)
        for(int j=9*i+2;j<=n;j++){//j=>D
                s+=number[j-x]*number[j-x+2*i];
                d[j]+=s*number[j-i];
                c[j-i]+=s*number[j];
        }


        s=0;
        x=8*i+1;//x=>min(C-A)
        for(int j=n-9*i-1;j>=1;j--){//j=>A
            s+=number[j+x]*number[j+x+i];
            a[j]+=s*number[j+2*i];
            b[j+2*i]+=s*number[j];
        }
    }
    for(int i=1;i<=m;i++){
        cout<<a[itemValue[i]]<<' '<<b[itemValue[i]]<<' '<<c[itemValue[i]]<<' '<<d[itemValue[i]]<<endl;
    }
    return 0;
}
/*
30 8
1
24
7
28
5
29
26
24

*/
