#include <cstdio>
char in[5][2],s[5];
void dfs(int a,int b,int c,int h) {//a为初始柱**b为中途柱**c为结束柱**h为移动个数 
	if(h==0) return;
	dfs(a,c,b,h-1);
	printf("%c->%d->%c\n",s[a],h,s[b]);
	dfs(c,b,a,h-1);
}
int main() {
	int n;
	scanf("%d%s%s%s",&n,in[0],in[1],in[2]);
	for(int i=0; i<3; i++) s[i]=in[i][0];
	dfs(0,1,2,n);
	return 0;
}
