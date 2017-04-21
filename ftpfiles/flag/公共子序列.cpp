#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int d[1000][1000];
char a[1555],b[16161];

int lcs(int i,int j) {
	if(d[i][j]!=0) {
		return d[i][j];
	}
	if(i==0||j==0) {
		d[i][j]=0;
		return d[i][j];
	}
	if(a[i-1]==b[j-1]) {//表示元素下标 
		d[i][j]=lcs(i-1,j-1)+1;
		return d[i][j];
	}
	if(a[i-1]!=b[j-1]) {
		int t=lcs(i-1,j);
		int y=lcs(i,j-1);
		if(t>=y) {
			d[i][j]=t;
		} else d[i][j]=y;
		return d[i][j];
	}
}

int main() {
	int i=1,j=1;
	cin>>a>>b;
	cout<<lcs(strlen(a),strlen(b))<<endl;
	return 0;
}


