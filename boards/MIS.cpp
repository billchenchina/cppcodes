/*
 * This program aims to solve the MIS Problem
 * MIS : Maximum Interval Sum
 */

#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector<int>v;
	int m,sum;
	int n;
    //input the size of the array
    cin>>n;
    //input array v[]
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    //preprocess
    m=v[0];
    sum=v[0];
	for(int i=1;i<v.size();i++){
	    sum=max(sum,0);
	    sum+=v[i];
	    m=max(m,sum);
	}
    //output answer
    cout<<m;
}