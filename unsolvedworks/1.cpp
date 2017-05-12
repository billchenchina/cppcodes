#include <iostream>

#define arrayLength 50
#define nodeTreeLength 3*(arrayLength+1)
#define max(x,y) x>y?x:y
using namespace std;

struct node{
	int leftNode;
	int rightNode;
	int sumNum;
	int maxNum;
};

node nodeTree[arrayLength];
int originArray[nodeTreeLength];
void buildTree(int,int,int);
void update(int,int,int);
int getSum(int,int,int);
int getMax(int,int,int);
int main(){
	int left,right;
	left=1;
	cin>>right;
	for(int i=1;i<=right;i++){
		cin>>originArray[i];
	}
	buildTree(1,1,right);


    int querynum;
    cin>>querynum;
    while(querynum--){
        int from,to,option;
        cin>>option>>from>>to;
        if(option==1){
            cout<<getMax(1,from,to);
        }else if(option==2){
            cout<<getSum(1,from,to);
        }
    }
    return 0;
}

void buildTree(int tempRoot,int left,int right){
	nodeTree[tempRoot].leftNode=left;
	nodeTree[tempRoot].rightNode=right;
	if(left==right){
		nodeTree[tempRoot].maxNum=originArray[left];
		nodeTree[tempRoot].sumNum=originArray[left];
	}
	else{
		int mid=(left+right)/2;
		buildTree(tempRoot*2,left,mid);
		buildTree(tempRoot*2+1,mid+1,right);
	}
}

void update(int tempRoot,int position,int value){
	if(nodeTree[tempRoot].leftNode==nodeTree[tempRoot].rightNode){
		nodeTree[tempRoot].maxNum=value;
		nodeTree[tempRoot].sumNum=value;
	}else{
		int mid=(nodeTree[tempRoot].leftNode+nodeTree[tempRoot].rightNode)/2;
		if(position<=mid){
			update(tempRoot*2,position,value);
		}else{
			update(tempRoot*2+1,position,value);
		}
		nodeTree[tempRoot].sumNum=nodeTree[tempRoot*2].sumNum+nodeTree[tempRoot*2+1].sumNum;
		nodeTree[tempRoot].maxNum=max(nodeTree[tempRoot*2].maxNum,nodeTree[tempRoot*2+1].maxNum);
	}
}

int getSum(int tempRoot,int left,int right){
	if(nodeTree[tempRoot].leftNode==nodeTree[tempRoot].rightNode){
		return nodeTree[tempRoot].sumNum;
	}else{
		int mid=(nodeTree[tempRoot].leftNode+nodeTree[tempRoot].leftNode)/2;
		if(right<=mid)return getSum(tempRoot*2,left,right);
		else if(left>mid)return getSum(tempRoot*2+1,left,right);
		else{
			return getSum(tempRoot*2,left,right)+getSum(tempRoot*2+1,left,right);
		}
	}
}

int getMax(int tempRoot,int left,int right){
	if(nodeTree[tempRoot].leftNode==nodeTree[tempRoot].rightNode){
		return nodeTree[tempRoot].maxNum;
	}else{
		int mid=(nodeTree[tempRoot].leftNode+nodeTree[tempRoot].rightNode)/2;
		if(left>mid){
			return getMax(tempRoot*2+1,left,right);
		}else if(right<=mid){
			return getMax(tempRoot*2,left,right);
		}else{
			return max(getMax(tempRoot*2,left,right),getMax(tempRoot*2+1,left,right));
		}
	}
}
