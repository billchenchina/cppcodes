#include <bits/stdc++.h>

using namespace std;

struct node {
    int value;
    int totaladd;
    node *lchild;
    node *rchild;
    int l_range;
    int r_range;
    int mid;
    node(int l,int r) {
        totaladd=0;
        value=0;
        if(l==r) {
            lchild=rchild=NULL;
            mid=l_range=r_range=l;

            return;
        }
        mid=l+(r-l)/2;
        lchild=new node(l,mid);
        rchild=new node(mid+1,r);
        l_range=l;
        r_range=r;
    }
    void addValue(int l,int r,int val) {
        if(l==r) {
            value+=val;
            return;
        } else {
            if(l==l_range&&r==r_range) {
                totaladd+=val;
            }
            // 算啦算啦 再给 node 类价格成员变量 mid 吧。。。
            // 只是比较好写 233333
            // 看起来没有问题？
            // （还是只是错觉？
            // 突然想起来个事 OI 最大错觉其实是自己的答案过了样例
            else if(r<=mid) {
                this->lchild->addValue(l,r,val);
            } else if(l>=mid+1) {
                this->rchild->addValue(l,r,val);
            } else {
                this->lchild->addValue(l,mid,val);
                this->rchild->addValue(mid+1,r,val);
            }
        }
    }
    /*
        err...刚才看到的那个没有开的直播间是我们同学 同学习信息竞赛...
        昨天就是他惨遭电脑锁屏杀...开着直播呢...人出去吃饭了 结果 hhh
    */
    int query(int l,int r) {
        int add=totaladd;
        totaladd=0;
        this->lchild->addValue(l,mid,add);
        this->rchild->addValue(mid+1,r,add);
        if(l==l_range&&r==r_range) {
            return this->lchild->query(l,mid)+this->rchild->query(mid+1,r);
        } else if(r<=mid) {
            return this->lchild->query(l,r);
        } else if(l>=mid+1) {
            return this->rchild->query(l,r);
        } else {
            return this->lchild->query(l,mid)+this->rchild->query(mid+1,r);
        }
    }

};



int main() {
    int N,M;
    cin>>N>>M;
    node *root=new node(1,N); //构造函数手残打错23333
    for(int i=1; i<=N; i++) {
        int tmp;
        cin>>tmp;
        root->addValue(i,i,tmp);
    }
    // opps...
    while(M--) {
        int opt;
        int l_range;
        int r_range;
        cin>>opt>>l_range>>r_range;
        if(opt==1) {
            int k;
            cin>>k;
            root->addValue(l_range,r_range,k);
        } else {
            cout<<root->query(l_range,r_range)<<endl;
        }
    }
    return 0;

}
