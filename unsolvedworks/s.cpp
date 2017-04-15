#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Query{
    int from,to;
    Query(int a,int b){
        from=a;
        to=b;
    }
    Query(){}
};
inline void save(int,int);
void getGlobalRoot();
void doLCA(int);
void input();
void preP();//pre_process
int getAncestor(int);
void output();


int vis[500];
int T;
int GlobalRoot;
vector<int>son[500];
vector<Query>querys;
int Result[500];
int Father[500];
int Ancestor[500];
int pointNum,lineNum,queryNum;

int main(){
    cin>>T;
    int i;
    for(i=0;i<T;++i){
        input();
        doLCA(GlobalRoot);
	output();
    }
	return 0;
}

void input(){
    cin>>pointNum;
    lineNum=pointNum-1;
    int i;
    preP();
    for(i=0;i<lineNum;++i){
        int tmpF,tmpS;
        cin>>tmpF>>tmpS;
        son[tmpF].push_back(tmpS);
        Father[tmpS]=tmpF;
    }

    cin>>queryNum;
    for(int i=0;i<queryNum;++i){
        int u,v;
        cin>>u>>v;
        querys.push_back(Query(u,v));
        querys.push_back(Query(v,u));
    }
    getGlobalRoot();
}

void preP(){
	fill(Father, Father+500,0);
	fill(Result,Result+500,0);
	querys.clear();
	fill(vis,vis+500,0);
	for(int i=0;i<=pointNum;i++){
		son[i].clear();
		Ancestor[i]=i;
	}
}

void doLCA(int p){
    for(int i=0;i<son[p].size();++i){
        doLCA(son[p][i]);
    }
    for(int i=0;i<querys.size();++i){
    	if(querys[i].from==p&&vis[querys[i].to]==true){
            save(i,getAncestor(querys[i].to));
    	}
    }
    vis[p]=true;
    Ancestor[p]=Father[p];
    getAncestor(p);
    return;
}
inline void save(int queryi,int sharedAncestor){
    Result[queryi]=sharedAncestor;
}
int getAncestor(int p){
	if(Ancestor[p]==p)return p;
	else{
		Ancestor[p]=getAncestor(Ancestor[p]);
		return Ancestor[p];
	}
}
void getGlobalRoot(){
	for(int i=1;i<=pointNum;i++){
		if(Father[i]==0)GlobalRoot=i;
	}
	return;
}

void output(){
    for(int i=0;i<queryNum;++i){
        cout<<Result[i]<<endl;
    }
}
