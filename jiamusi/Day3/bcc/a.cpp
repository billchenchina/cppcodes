#include <bits/stdc++.h>

using namespace std;
double getTime(double pos,vector<pair<int,int> >v){ //+1s
    double ret=0;
    for(int i=0;i<v.size();i++){
        double thist=abs(pos-v[i].first)/v[i].second;
        ret=thist>ret?thist:ret;

    }
    return ret;
}

int main(){
    // Do something
    int n;
    #ifdef bccdbg
    time_t start_t,end_t;
    start_t=clock();
    cin>>n;
    #else
    scanf("%d",&n);
    #endif // bccdbg

    vector<pair<int,int> >v;
    double minn=static_cast<double>(INT_MAX);
    double maxn=static_cast<double>(-1);
    for(int i=0;i<n;i++){
        int x;
        #ifdef bccdbg
        cin>>x;
        #else
        scanf("%d",&x);
        #endif // bccdbg
        minn=x<minn?x:minn;
        maxn=x>maxn?x:maxn;
        v.push_back(pair<int,int>());
        v[i].first=x;
    }
    for(int i=0;i<n;i++){
        int x;
        #ifdef bccdbg
        cin>>x;
        #else
        scanf("%d",&x);
        #endif // bccdbg

        v[i].second=x;
    }
    double L=minn,R=maxn;
    #ifdef bccdbg
    //int a;
    //while(cin>>a){
    //    cout<<getTime(a,v)<<endl;
    //}
    //cout<<L<<' '<<R<<endl;
    #endif // bccdbg
    while(true){
        double place1=L+(R-L)/3;
        double place2=L+(R-L)/3*2;
        if(getTime(place1,v)<getTime(place2,v)){
            R=place2;
        }else{
            L=place1;
        }
        if(R-L<=0.00000000001){
            break;
        }
        #ifdef bccdbg
        cout<<double(L)<<' '<<double(R)<<endl;
        #endif // bccdbg
    }
    //cout<<R<<endl;
    printf("%.8lf\n",getTime(R,v));
    #ifdef bccdbg
    end_t=clock();
    ofstream timeout("time.dbg");
    timeout<<end_t-start_t;
    #endif // bccdbg
    return 0;
}
