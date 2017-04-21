//多重背包
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
/*
样例输入1：
5 1000
80 20 4
40 50 9
30 50 7
40 30 6
20 20 1
样例输出1：
1040
*/
int main()
{
    freopen("party.out","w",stdout);freopen("party.in","r",stdin);
    int n,m;//n代表物品种类数，m表示背包容量
    int i,j,k,v;
    int f[200][2000]= {0},val[200],w[200],s[200];
    cin>>n>>m;//
    for(i=1; i<=n; i++)
    {
        cin>>w[i]>>val[i]>>s[i];
    }
    for(i=1; i<=n; i++)
    {
        for(v=1; v<=m; v++)
        {
            f[i][v]=f[i-1][v];
            for(k=0; k<=s[i]; k++)
            {
                if(w[i]*k<=v)
                {
					//f[i][v] = max(f[i][v], f[i-1][v-k*w[i]]+k*val[i]);
					if(f[i-1][v-k*w[i]]+k*val[i]>f[i][v]){
                        f[i][v]=f[i-1][v-k*w[i]]+k*val[i];
					}
                }
                else{
                    break;
                }
            }
        }
    }

    for(i=1;i<=n;i++){
        for(v=0;v<=m;v+=10){
            printf("%5d",f[i][v]);
        }
        cout<<endl;
    }

    cout<<f[n][m];
    fclose(stdout);
    return 0;
}



void WKnapsack4(int *value, int* v, int *Num, int n, int V)
{
	int d[100][100];
	memset(d, 0, sizeof(int)* 100*100);
	bool  visit[100][100];
	memset(visit, 0, sizeof(bool)* 100 * 100);
	int  times[100][100];
	memset(times, 0, sizeof(int)* 100 * 100);

	for (int i = 0; i < n; i++)
	{
		for (int j = v[i]; j <= V; j++)
		{
			for (int k = 0; k <= Num[i]; k++)
			{
				if (i == 0)
				{
					d[i][j] = 0;
				}
				else if(j >= k*v[i])
				{
					if (d[i][j] < d[i - 1][j - k*v[i]] + k*value[i])
					{
						visit[i][j] = true;
						times[i][j] = k;
					}
					d[i][j] = max(d[i][j], d[i - 1][j - k*v[i]] + k*value[i]);
				}
			}


		}
	}
	printf("%d ", d[n-1][V]);
	//多重背包，打印
	printf("打印路径:\n");
	for (int i = n - 1, j = V; i >= 0 && j>0; i--)
	{
		if (visit[i][j]) //
		{
			printf("value:%d  num:%d\n",value[i], times[i][j]);
			j = j - v[i];
		}
	}

}
