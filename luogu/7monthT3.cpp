#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int L,N;
    cin>>L>>N;
    int x[100001],r[100001];
    int dist;
    priority_queue q;

    for(int i=0; i<N; i++)
    {
        cin>>x[i]>>r[i];
        q.push(x[i]);
    }
}
