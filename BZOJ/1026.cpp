#include <cstdio>
#include <cstdlib>

using namespace std;

int solve(int num)
{
  int dp_map[11][10][2]={0};
  int digit[11];
  int len=0;
  while(num)
  {
    digit[len]=num%10;
    num/=10;
    len++;
  }
    for(int j=0;j<10;++j)
    {
        dp_map[0][j][0]=1;
    }
  for(int i=1;i<=len;++i)
  {
    for(int j=0;j<10;++j)
    {
      for(int k=0;k<10;++k)
      {
        dp_map[i][j][0]+=dp_map[i-1][k][0];
      }
    }
  }

}

int main()
{
  int A,B;
  scanf("%d%d",&A,&B);
  printf("%d",solve(B)-solve(A-1));
}
