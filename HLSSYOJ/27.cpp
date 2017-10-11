#include <bits/stdc++.h>

using namespace std;

struct cmp
{
    bool operator()(const pair<int,int>&p1,const pair<int,int>&p2)
    {
        return p1.second>p2.second;
    }
};


int main()
{
    int T;
    scanf("%d",&T);
    char choice[4][1008];
    pair<int,int>len[4];
    while(T--)
    {
        for(int i=0; i<4; ++i)
        {
            scanf("%s",choice[i]);
            len[i].first=i;
            len[i].second=0;
            int str_len=strlen(choice[i]);
            for(int j=2; j<str_len; ++j)
            {
                if(choice[i][j]!='_')
                {
                    len[i].second++;
                }
            }
        }
        sort(len,len+4,cmp());
        int lucky=2;
        int lucknum=0;
        // for the max
        bool a_not_lucky=0;
        for(int i=1; i<4; ++i)
        {
            if(len[0].second<2*len[i].second)
            {
                a_not_lucky=true;
            }
        }
        // for the min
        bool d_not_lucky=0;
        for(int i=0; i<3; ++i)
        {
            if(2*len[3].second>len[i].second)
            {
                d_not_lucky=true;
            }
        }
        if(a_not_lucky^d_not_lucky)
        {
            if(a_not_lucky)
            {
                printf("%c\n",'A'+len[3].first);
                continue;
            }
            if(d_not_lucky)
            {
                printf("%c\n",'A'+len[0].first);
                continue;
            }
            printf("C\n");
            continue;
        }
        printf("C\n");
    }
}
