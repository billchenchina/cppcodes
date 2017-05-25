/*
 * Unfinished
 *
**/
#include <vector>
#include <fstream>
#define MODNUM 10007
using namespace std;
struct node {
    int color;
    int number;
    int place;
};
typedef vector<node> nodelist;
#ifndef BILLCHENCHINADEBUGONPC
#ifdef ONLINE_JUDGE
#include <iostream>
#else
#define cin fin
#define cout fout
#endif // ONLINE_JUDGE
#else
#include <iostream>
#endif // BILLCHENCHINADEBUGONPC



int main() {
    ifstream fin("sum.in");
    ofstream fout("sum.out");
    int n,m;
    cin>>n>>m;
    vector<node> ArrayList(n+1);
    vector<int> sumNtimesN(n+1);
    // s_list[odd/even][color]
    vector<vector<nodelist> > s_list(2,vector<nodelist>(m+1));

    int sum=0;
    for(int i=1; i<=n; i++) {
        cin>>ArrayList[i].number;
        ArrayList[i].place=i;
        sumNtimesN[i]=i*ArrayList[i].number;
    }
    for(int i=1; i<=n; i++) {
        cin>>ArrayList[i].color;
        s_list[i%2][ArrayList[i].color].push_back(ArrayList[i]);
    }
    for(int i=1; i<=m; i++) {
        //s_list[][color=i]

        for(int j=0; j<2; j++) {
            int tmpttl=0;
            for(int k=0; k<s_list[j][i].size(); k++) {
                tmpttl+=sumNtimesN[s_list[j][i][k].place];
                tmpttl%=MODNUM;
            }
            tmpttl*=(s_list[j][i].size()-2);
            tmpttl%=MODNUM;
            sum+=tmpttl;
            sum%=MODNUM;
            int ttl=0;
            int ttl2=0;
            for(int k=0; k<s_list[j][i].size(); k++) {
                ttl+=s_list[j][i][k].place;
                ttl%=MODNUM;
                ttl2+=s_list[j][i][k].number;
                ttl2%=MODNUM;
            }
            int tmp=ttl*ttl2;
            tmp%=MODNUM;
            sum+=tmp;
            sum%=MODNUM;

        }

    }

    cout<<sum;
    return 0;
}
