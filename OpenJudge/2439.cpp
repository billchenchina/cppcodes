//Unfinished
#include <iostream>
#define mix(x,y) x+(y-x)/2
using namespace std;
struct cowRange {
    int leftRange;
    int rightRange;
    int maxInRange;
    int minInRange;
    cowRange *lchild,*rchild;
    cowRange(int leftR,int rightR) {
        this->leftRange=leftR;
        this->rightRange=rightR;
        this->maxInRange=0;
        this->minInRange=INT_MAX;
        if(leftR==rightR) {
            this->lchild=this->rchild=NULL;
            return;
        } else {
            int middle=mix(leftR,rightR);
            lchild=new cowRange(leftR,middle);
            rchild=new cowRange(middle+1,rightR);
        }
    }
    void addNum(int position,int value) {
        this->maxInRange=max(this->maxInRange,value);
        this->minInRange=min(this->minInRange,value);
        if(this->leftRange==this->rightRange&&position==this->leftRange) {
            return;
        } else if(mix(this->rightRange,this->leftRange)>=position) {
            lchild->addNum(position,value);
        } else if(mix(this->rightRange,this->leftRange)<position) {
            rchild->addNum(position,value);
        }
    }
    /*
    This part is no use
    int searchValueInRange(int leftR,int rightR){
        if(leftR==this->leftRange&&rightR==this->rightRange){
            return this->maxInRange-this->minInRange;
        }else if(mix(this->leftRange,this->rightRange)>=rightR){
            return this->lchild->searchValueInRange(leftR,rightR);
        }else if(mix(this->leftRange,this->rightRange)<leftR){
            return this->rchild->searchValueInRange(leftR,rightR);
        }else{

        }
    }*/
};

int main() {
    int N,Q;
    cin>>N>>Q;
    cowRange *root=new cowRange(1,N);
    for(int i=1; i<=N; i++) {
        int tmp;
        cin>>tmp;
        root->addNum(i,tmp);
    }
    for(int i=1; i<=Q; i++) {
        int l,r;
        cin>>l>>r;

    }

}

