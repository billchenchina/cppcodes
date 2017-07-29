#include <bits/stdc++.h>

using namespace std;

/**
  * 快速幂
  *
  * @return (a^b)%mod
  *
  **/

int fastpow(int a,int b,int mod);

/**
  *
  * @return hash of vector<int>
  *
  **/

int my_hash(vector<int>v,int maxn);

/**
  * Calculate Beautiful Number
  *
  *
  **/

int beautiful(vector<int>v,int maxn,int k) {
    vector<vector<int> >subvectors;
    set<vector<int> >s;
    for(int i=0; (i+1)*k<=v.size(); i++) {
        subvectors.push_back(vector<int>(v.begin()+i*k,v.begin()+i*k+k));
    }
    int ret=0;
    for(int i=0; i<subvectors.size(); i++) {
        bool flag=0;
        vector<int>new_reverse_vector=subvectors[i];
        reverse(new_reverse_vector.begin(),new_reverse_vector.end());
        if(my_hash(new_reverse_vector,maxn)==my_hash(subvectors[i],maxn)) {
            for(int j=0; j<(new_reverse_vector.size()>>1)+1; j++) {
                if(new_reverse_vector[j]!=subvectors[i][j]) {
                    flag=1;
                }
            }
        }
        /**
          *
          * Two vectors are not equal
          *
          **/
        if(flag==1) {
            //
            s.insert(new_reverse_vector);
            s.insert(subvectors[i]);
        } else {
            //
            if(s.find(new_reverse_vector)==s.end()) {
                s.insert(new_reverse_vector);
                ret+=1;
            }
        }
    }
    return (s.size()+ret)>>1;
}


int main() {
    int n;
    cin>>n;
    vector<int>a(n,0);
    int maxn=-1;
    for(int i=0; i<n; i++) {
        cin>>a[i];
        if(maxn>a[i])maxn=a[i];
    }

    int L=1,R=n;
    while(L<=R) {
        if(L==R)break;
        if(L+1==R) {
            int pos1=L;
            int pos2=R;
            int check_of_pos1,check_of_pos2;
            check_of_pos1=beautiful(a,maxn,pos1);
            check_of_pos2=beautiful(a,maxn,pos2);
            if(check_of_pos1<check_of_pos2) {
                L=R;
                continue;
            } else if(check_of_pos1>check_of_pos2) {
                R=L;
                continue;
            } else {
                break;
            }
        }
        if(L+2==R) {
            int checka,checkb,checkc;
            checka=beautiful(a,maxn,L);
            checkb=beautiful(a,maxn,L+1);
            checkc=beautiful(a,maxn,L+2);
            if(checka>checkb)R=L;
            else if(checkb>checka&&checkb>checkc)L=R=L+1;
            else if(checkc>checkb)L=R;
            else if(checka==checkb)R--;
            else if(checkb==checkc)L++;

        }
        int pos1=L+(R-L)/3;
        int pos2=R-(R-L)/3;
        int check_of_pos1,check_of_pos2;
        check_of_pos1=beautiful(a,maxn,pos1);
        check_of_pos2=beautiful(a,maxn,pos2);
#ifdef bccdbg
        cout<<"L&R "<<L<<' '<<R<<endl;
        cout<<pos1<<' '<<check_of_pos1<<endl;
        cout<<pos2<<' '<<check_of_pos2<<endl;
        system("pause");
#endif // bccdbg
        if(check_of_pos1<check_of_pos2)L=pos1;
        else R=pos2;

        /* To be rewrite*/
    }
#ifdef bccdbg
    cout<<endl<<endl;
    cout<<"============ Final Answer ============"<<endl;
    cout<<endl<<endl;
#endif // bccdbg
    if(L==R) {
        cout<<beautiful(a,maxn,L)<<endl;
        cout<<1<<endl;
        cout<<L<<endl;
    } else {
        cout<<beautiful(a,maxn,L)<<endl;
        cout<<R-L+1<<endl;
        for(int i=L; i<=R; i++) {
            cout<<i<<endl;
        }
    }
#ifdef bccdbg
    cout<<endl<<endl;
    cout<<"====================================="<<endl;
    cout<<endl<<endl;

#endif // bccdbg


}
int fastpow(int a,int b,int mod) {
    if(b==1)return a%mod;
    else if(b==0)return 1;
    else {
        a%=mod;
        int tmp=fastpow(a,b/2,mod);
        tmp*=tmp;
        tmp%=mod;
        /**
          * b 为奇数
          *
          **/
        if((b&1)==1) {
            tmp*=a;
            tmp%=mod;
        }
        return tmp;
    }
}

int my_hash(vector<int>v,int maxn) {
    long long ret=0;
    int mod=maxn;
    if(mod%2==0)mod++;
    for(int i=0; i<v.size(); i++) {
        ret+=(static_cast<long long>(i)*fastpow(maxn,v[i],mod))%mod;
        ret%=mod;
    }
    return static_cast<int>(ret);
}

