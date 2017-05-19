#include <iostream>
#include<cstdio>
#include <vector>

#define null NULL
#define ll long long
#define mix(x,y) x+(y-x)/2
using namespace std;

struct node {
    node* lchild;
    node* rchild;
    int left,right;
    ll eachnum;
    ll ttlnum;
    node(int _left,int _right);
    void addvalue(int _left,int _right,ll value);
    ll get_total_value_in_this_node();
    ll query(int _left,int _right);
};
node::node(int _left,int _right) {
    this->left=_left;
    this->right=_right;
    this->eachnum=this->ttlnum=0;
    if(_left==_right) {
        this->lchild=null;
        this->rchild=null;
    } else {
        int mid=(_right-_left)/2+_left;
        this->lchild=new node(_left,mid);
        this->rchild=new node(mid+1,_right);
    }
}



void node::addvalue(int _left,int _right,ll value) {
    //cout<<"In node::addvalue("<<_left<<","<<_right<<","<<value<<")Node Information:left="<<this->left<<",right="<<this->right<<"\n";
    //printf("In node::addvalue(%d,%d,%lld)\n\tNode Information:left=%d,right=%d\n",_left,_right,value,this->left,this->right);
    if(_left==this->left&&_right==this->right) {
        eachnum+=value;
    } else {
        int mid=mix(this->left,this->right);
        this->ttlnum+=value*(_right-_left+1);
        if(_left>mid) {
            this->rchild->addvalue(_left,_right,value);
        } else if(_right<=mid) {
            this->lchild->addvalue(_left,_right,value);
        } else {
            this->lchild->addvalue(_left,mid,value);
            this->rchild->addvalue(mid+1,_right,value);
        }
    }
}
ll node::query(int _left,int _right) {

    if(_left==this->left&&_right==this->right) {
        ll tmp=0;
        tmp+=eachnum*(this->right-this->left+1);
        tmp+=ttlnum;
        return tmp;
    } else {
        this->ttlnum+=(this->right-this->left+1)*(this->eachnum);
        this->lchild->addvalue(this->lchild->left,this->lchild->right,this->eachnum);
        this->rchild->addvalue(this->rchild->left,this->rchild->right,this->eachnum);
        this->eachnum=0;
        int mid=mix(this->left,this->right);
        if(_left>mid) {
            return this->rchild->query(_left,_right);
            //
        } else if(_right<=mid) {
            return this->lchild->query(_left,_right);
            //
        } else {
            ll tmp=0;
            tmp+=this->lchild->query(_left,mid);
            tmp+=this->rchild->query(mid+1,_right);
            return tmp;
            //
            //
        }
    }

}
int main() {
    int N,Q;
    cin>>N>>Q;
    node *root=new node(1,N);
    //printf("root information:\n\tleft=%d,right=%d\n",root->left,root->right);
    for(int i=1; i<=N; i++) {
        ll tmp;
        cin>>tmp;
        root->addvalue(i,i,tmp);
    }
    //printf("root information:\n\tleft=%d,right=%d\n",root->left,root->right);
    for(int i=1; i<=Q; i++) {
        char option;
        cin>>option;
        vector<ll>argv(option=='Q'?2:3,0);
        for(int j=0; j<(option=='Q'?2:3); j++) {
            cin>>argv[j];
        }

        if(option=='C') {
            root->addvalue(argv[0],argv[1],argv[2]);
        } else {
            cout<<root->query(argv[0],argv[1])<<endl;
        }
    }
    return 0;
}
