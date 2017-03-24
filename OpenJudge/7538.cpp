#include<cstdio>
#include<iostream>
using namespace std;

int main() {
int q,w,e;
cin>>q>>w>>e;
if(q>w && w>e){cout<<q;}
else if(q>e && e>w){cout<<q;}
else if(w>e && e>q){cout<<w;}
else if(w>q && q>e){cout<<w;}
else if(e>q && q>w){cout<<e;}
else if(e>w && w>q){cout<<e;}
	return 0;
}