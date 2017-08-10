/**
 * Attention, please.
 * The problem on [hljssyzxOJ](http://hljssyzx.openjudge.cn/sjjg/tp01/)
 * don't have a special judge.
 * please join [Luogu/hljssyzx](https://www.luogu.org/team/show?teamid=3558)
 * and judge your problem there
 * special judge by billchenchina
 *
 *
 **/

#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
#define maxPersonAmount 102
#define perNum maxPersonAmount
int n;
/*
 * familyTree[person][i] is person 's child
 *
 */
inline void setFather(int father,int son);
int familyTree[perNum][perNum];
int nums[perNum];
int sonNum[perNum],fatherNum[perNum];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        while(true){
            int a;
            cin>>a;
            if(a!=0){
                setFather(i,a);
            }else break;
        }
    }
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(fatherNum[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int head=q.front();
        for(int i=0;i<nums[head];i++){
            int c=familyTree[head][i];
            fatherNum[c]--;
            if(fatherNum[c]==0){
                q.push(c);
            }
        }
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}

inline void setFather(int father,int son){
    sonNum[father]++;
    fatherNum[son]++;
    familyTree[father][nums[father]]=son;
    nums[father]++;
}
