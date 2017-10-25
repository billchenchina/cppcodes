#include <bits/stdc++.h>
using namespace std;

struct game_status
{
    int a;
    int b;
};
int mem[4][4][3]= {-1};
int a_arr[4][4];
int b_arr[4][4];
int a_win=0,b_win=0;
void get_result(int &a,int &b,long long &i)
{
    if(mem[a][b][0]!=-1)
    {
        a_win+=mem[a][b][1];
        b_win+=mem[a][b][2];
        i+=mem[a][b][0];
    }
    else if(a==1&&b==3)
    {
        a_win++;
    }
    else if(b==1&&a==3)
    {
        b_win++;
    }
    else if(a>b)
    {
        a_win++;
    }
    else if(b>a)
    {
        b_win++;
    }
    int a_=a,b_=b;
    a=a_arr[a_][b_];
    b=b_arr[a_][b_];
}

int main()
{
    long long k;
    int a,b;
    cin>>k>>a>>b;
    for(int i=1; i<=3; ++i)
    {
        for(int j=1; j<=3; ++j)
        {
            cin>>a_arr[i][j];
        }
    }
    for(int i=1; i<=3; ++i)
    {
        for(int j=1; j<=3; ++j)
        {
            cin>>b_arr[i][j];
        }
    }
    for(long long i=1; i<=k; ++i)
    {
        get_result(a,b,i);
    }
    cout<<a_win<<' '<<b_win;
}


/*
#include <iostream>
#include <algorithm>

using namespace std;

int stepA[3][3],stepB[3][3];

struct Data{
    long long scoreA;
    long long scoreB;
    long long index;
    Data() : scoreA(-1) ,scoreB(-1) , index(-1) {}
    Data(long long scoreA,long long scoreB,long long index) : scoreA(scoreA) , scoreB(scoreB) ,index(index) {}
};

int getResult(int a,int b){
    if(a == b){
        return 0;
    }else{
        switch(a){
        case 1:{
            switch(b){
                case 2: return -1;
                case 3: return 1;
            }
        }
        case 2:{
            switch(b){
                case 1: return 1;
                case 3: return -1;
            }
        }
        case 3:{
            switch(b){
                case 1: return -1;
                case 2: return 1;
            }
        }
        }
    }
}

bool visit[3][3];
Data mem[3][3];

int main(){
    long long k;
    int a,b;
    cin >> k >> a >> b;
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            cin >> stepA[i][j];
        }
    }
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            cin >> stepB[i][j];
        }
    }
    int doingA = a,doingB = b;
    long long countRounds = 0,scoreA = 0,scoreB = 0,repeatLength = -1,repeatScoreA = -1,repeatScoreB = -1;
    while(countRounds < k){
        switch(getResult(doingA,doingB)){
            case -1: {
                scoreB++;
                break;
            }
            case 0: {
                break;
            }
            case 1: {
                scoreA++;
                break;
            }
        }
        int newDoingA = stepA[doingA - 1][doingB - 1],newDoingB = stepB[doingA - 1][doingB - 1];
        doingA = newDoingA; doingB = newDoingB;
        countRounds++;
        if(visit[doingA - 1][doingB - 1]){
            repeatLength = countRounds - mem[doingA - 1][doingB - 1].index;
            repeatScoreA = scoreA - mem[doingA - 1][doingB - 1].scoreA;
            repeatScoreB = scoreB - mem[doingA - 1][doingB - 1].scoreB;
            break;
        }
        visit[doingA - 1][doingB - 1] = true;
        mem[doingA - 1][doingB - 1] = Data(scoreA,scoreB,countRounds);
    }
    if(repeatLength == -1){
        cout << scoreA << " " << scoreB << endl;
    }else{
        long long nowLeftRounds = k - countRounds;
        long long repeatTimes = nowLeftRounds / repeatLength;
        scoreA += repeatScoreA * repeatTimes;
        scoreB += repeatScoreB * repeatTimes;
        countRounds += repeatLength * repeatTimes;
        while(countRounds < k){
            switch(getResult(doingA,doingB)){
                case -1: {
                    scoreB++;
                    break;
                }
                case 0: {
                    break;
                }
                case 1: {
                    scoreA++;
                    break;
                }
            }
            int newDoingA = stepA[doingA - 1][doingB - 1],newDoingB = stepB[doingA - 1][doingB - 1];
            doingA = newDoingA; doingB = newDoingB;
            countRounds++;
        }
        cout << scoreA << " " << scoreB << endl;
    }
    return 0;

}
*/
