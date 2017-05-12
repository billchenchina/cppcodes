#include <iostream>
#include <vector>
using namespace std;

struct tree{
	int leftTree;
	int rightTree;
	int maxInTree;
	int minInTree;
}
void buildTree(int treeId,int leftNode,int rightNode);
tree Tree[200000];
vector<int>cowHeight;
int main(){
	int cowNum,queryNum;
	cin>>cowNum>>queryNum;
	vector<int>cowHeight(cowNum+1);
	for(int i=1;i<=cowNum;i++){
		cin>>cowHeight[i];
	}
	buildTree(1,1,cowNum);
}

void buildTree(int treeId,int leftNode,int rightNode){
	if(Tree[treeId].leftTree==Tree[treeId].rightTree){
		Tree[treeId].maxInTree=cowHeight[Tree[treeId].leftTree];
		Tree[treeId].minInTree=cowHeight[Tree[treeId].leftTree];
	}else{
		
	}
}