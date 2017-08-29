
#include <bits/stdc++.h>

using namespace std;

int N;

int main()
{
    scanf("%d",&N);
    for(int i=0;i<N;++i)
    {
        int father,k;
        scanf("%d%d",&father,&k);
        for(int i=0;i<k;++i)
        {
            int son;
            scanf("%d",&son);
            addedge(father,son);
        }
    }
}
