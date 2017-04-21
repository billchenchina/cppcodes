#include <iostream>
#include <cstdio>

using namespace std;
struct node {
    int num;
    int time;
    node (int n,int t) {
        num=n;
        time=t;
    }
    node() {};
};
int N,K;
node q[1001];
node * head,* tail;
int bfs();
void insertnode(node n);
node popnode();

int main() {
    cin>>N>>K;
    head=q;
    tail=q;
    insertnode(node(K,K,0));
    bfs();
}
void insertnode(node n) {
    *tail=n;
    tail++;
}
node popnode() {
    node n=*head;
    head++;
    return n;
}
node n;
int bfs() {
    while(head!=tail) {
        node n=popnode();
        if(n.num+1==N) {
            return n.time+1;
        }else{
            insertnode(node(n.num+1,n.num,n.time+1));
        }
        if(n.num-1==N){
            return n.time+1;
        }else if(n.num-1>=0){
            insertnode(node(n.num-1,n.num,n.time+1));
        }
        if(n.num*2==N){
            return n.time+1;
        }else{
            insertnode(node(n.num*2,n.num,n.time+1));
        }
    }
}
