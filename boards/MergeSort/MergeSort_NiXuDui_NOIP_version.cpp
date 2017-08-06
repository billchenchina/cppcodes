
/**
 * This file is a NOIP version of MergeSort_NiXuDui.cpp
 *
 * Optimized for speed
 *
 * Updated on 17/08/06 cc_2017_dbsdfz_train
 */


#include <iostream>
using namespace std;


inline int read(){
    int Num;
    char ch;
    while((ch=getchar())<'0'||ch>'9');
    Num=ch-'0';
    while((ch=getchar())>='0'&&ch<='9'){
        Num=Num*10+ch-'0';
    }
    return Num;
}


int v[1000006];
int tmp[1000006];
long long ans=0;
void Merge(int l,int mid,int r)
{
    int l_p=l,r_p=mid;
    int tmp_p=0;
    while(l_p!=mid&&r_p!=r){
        if(v[l_p]<=v[r_p]){
            tmp[tmp_p++]=v[l_p++];
        }else{
            tmp[tmp_p++]=v[r_p++];
            ans+=mid-l_p;
        }
    }
    while(l_p!=mid){
        tmp[tmp_p++]=v[l_p++];
    }

    while(r_p!=r){
        tmp[tmp_p++]=v[r_p++];
    }
    std::copy(tmp,tmp + tmp_p,v+l);
    return;
}

void MergeSort(int l,int r){

    if(l+1==r){
        return;
    }
    int mid=l+((r-l)>>1);
    MergeSort(l,mid);
    MergeSort(mid,r);
    Merge(l,mid,r);
    return;
}



int main(){
    int vsize=read();
    //scanf("%d",&vsize);

    for(int i=0;i<vsize;i++){
        //scanf("%d",&v[i]);
        v[i]=read();
    }
    MergeSort(0,vsize);
    printf("%lld",ans);

}
