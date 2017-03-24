#include <cstdio>
#include <iostream>
using namespace std;
int n,m,q;
int fa[20001];
void connect(int,int);
int findfather(int);
int main() {
    //freopen("relation.in","r",stdin);
    //freopen("relation.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    for(int i=1;i<=m;i++){
        int f,t;
        scanf("%d%d",&f,&t);
        connect(f,t);
    }
    scanf("%d",&q);
    for(int i=1;i<=q;i++){
        int c,d;
        scanf("%d%d",&c,&d);
        if(findfather(c)==findfather(d)){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    return 0;
}
int findfather(int c){
    while(fa[c]!=c){
        c=fa[c];
    }
    return c;
}
void connect(int p1,int p2){
    if(findfather(p1)==findfather(p2)){
        return;
    }else if(fa[p2]==p2){
        fa[p2]=p1;
    }else{
        int p2sf=findfather(p2);
        fa[p2sf]=p1;
    }
}