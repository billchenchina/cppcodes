#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int solve(int num)
{
    if(num==0)
    {
        return 1;
    }
    if(num<10)
    {
        return num+1;
    }
    int dp_map[11][10]= {0};
    int digit[11];
    int dp2[11]={0};
    int len=0;
    while(num)
    {
        digit[len]=num%10;
        num/=10;
        len++;
    }
    for(int j=0; j<10; ++j)
    {
        dp_map[0][j]=1;
    }

    dp2[0]=1;
    for(int i=1; i<len; ++i)
    {
        for(int j=0; j<10; ++j)
        {
            for(int k=0; k<10; ++k)
            {
                if(abs(j-k)>=2)
                    dp_map[i][j]+=dp_map[i-1][k];
            }
            if(digit[i-1]<j)
            {
                continue;
            }
            else if(abs(digit[i]-j)>=2)
            {
                dp2[i]+=dp_map[i-1][j];
            }
    }
    }
    cout<<dp_map[1][0]<<endl;
    int ans=0;
    for(int i=0;i<digit[len-1];++i)
    {
        ans+=dp_map[len-1][i];
    }
    ans+=dp2[len-1];
    return ans;
}

int main()
{
    int A,B;
    scanf("%d%d",&A,&B);
    printf("%d",solve(B)-solve(A-1));
}
