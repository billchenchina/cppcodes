#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int>edges[500];
vector<int>dfn(500,0);
vector<int>low(500,0);
vector<bool>isInStack(500,0);
int NODE_NUM,EDGE_NUM;
int totalTime=0;
stack<int>sta;
int totalNum;
void tarjan(int);

int main(){
    cin>>NODE_NUM>>EDGE_NUM;
    for(int i=1;i<=EDGE_NUM;i++){
        int frompoint,topoint;
        cin>>frompoint>>topoint;
        edges[frompoint].push_back(topoint);
    }
    for(int i=1;i<=NODE_NUM;i++){
        if(dfn[i]!=0){
            tarjan(i);
        }
    }
}

void tarjan(int thisnode){
    totalTime++;
    dfn[thisnode]=low[thisnode]=totalTime;
    sta.push(thisnode);
    isInStack[thisnode]=true;
    for(int i=0;i<edges[thisnode].size();i++){
        int nextnode=edges[thisnode][i];
        if(dfn[nextnode]==0){
            tarjan(nextnode);
            low[thisnode]=min(low[thisnode],low[nextnode]);

        }else if(isInStack[nextnode]!=false){
            low[thisnode]=min(low[thisnode],dfn[nextnode]);
        }
        if(dfn[thisnode]==low[nextnode]){
            totalNum++;
            while(thisnode!=nextnode){
                    //continue here!!
            }
        }
    }
}
