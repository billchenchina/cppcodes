#include <iostream>
#include <vector>
using namespace std;

// 10
// 8 4 1 8 48   787 41 51 156 6
template <typename T>
vector<T> Merge(vector<T>v1,vector<T>v2,int &NIXUnumber)
{
    typename vector<T>::iterator v1iter=v1.begin(),v2iter=v2.begin();
    vector<T> ansArr;
    while(v1iter!=v1.end()&&v2iter!=v2.end()){
        if(*v1iter<*v2iter){
            ansArr.push_back(*v1iter);
            v1iter++;
        }else if(*v1iter>=*v2iter){
            ansArr.push_back(*v2iter);
            v2iter++;
            NIXUnumber+=v1.end()-v1iter;
        }
    }
    while(v1iter!=v1.end()){
        ansArr.push_back(*v1iter);
        v1iter++;
    }

    while(v2iter!=v2.end()){
        ansArr.push_back(*v2iter);
        v2iter++;
    }
    return ansArr;
}


template <typename T>
vector<T> MergeSort(vector<T> v,int &NIXUnumber){

    if(v.size()==1){
        return v;
    }

    typename vector <T>::iterator miditerator=v.begin()+(v.size()/2);
    vector<T> v1(v.begin(),miditerator)
             ,v2(miditerator,v.end());

    v1=MergeSort(v1,NIXUnumber);
    v2=MergeSort(v2,NIXUnumber);

    return Merge(v1,v2,NIXUnumber);
}



template <typename T>
void output(vector<T>v){
    //for(typename vector<T>::iterator iter=v.begin();iter!=v.end();iter++){
    //    cout<<*iter<<' ';
    //}
}


int main(){
    vector<int>v;
    int vsize;
    cin>>vsize;
    for(int i=0;i<vsize;i++){
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    int NIXUnumber=0;
    output(MergeSort(v,NIXUnumber));
    cout<<NIXUnumber;

}

