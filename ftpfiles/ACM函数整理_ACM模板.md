# ACM函数整理

>ACM 计算机学院 USTAR 团队整理
>
>Billchenchina 转化为 Markdown 形式

## 数学问题

### 精度计算——大数阶乘

语法：
>int result=factorial(int n);

参数：
>n：n 的阶乘

返回值：阶乘结果的位数
>注意：本程序直接输出n!的结果，需要返回结果请保留long a[]
>
>需要 math.h

源程序： 
```cpp
int factorial(int n)
{
    long a[10000];
    int i,j,l,c,m=0,w;
    a[0]=1;
    for(i=1; i<=n; i++)
    {
        c=0;
        for(j=0; j<=m; j++)
        {
            a[j]=a[j]*i+c;
            c=a[j]/10000;
            a[j]=a[j]%10000;
        }
        if(c>0)
        {
            m++;
            a[m]=c;
        }
    }
    w=m*4+log10(a[m])+1;
    printf("\n%ld",a[m]);
    for(i=m-1; i>=0; i--) printf("%4.4ld",a[i]);
    return w;
}
```

### 精度计算——乘法（大数乘小数）

语法：
>mult(char c[],char t[],int m);

参数：
>c[]：被乘数，用字符串表示，位数不限
>
>t[]：结果，用字符串表示
>
>m：乘数，限定10以内

返回值：null
>注意：需要 string.h

源程序： 
```cpp
void mult(char c[],char t[],int m)
{
    int i,l,k,flag,add=0;
    char s[100];
    l=strlen(c);
    for (i=0; i<l; i++)
        s[l-i-1]=c[i]-'0';
    for (i=0; i<l; i++)
    {
        k=s[i]*m+add;
        if (k>=10)
        {
            s[i]=k%10;
            add=k/10;
            flag=1;
        }
        else
        {
            s[i]=k;
            flag=0;
            add=0;
        }
    }
    if (flag)
    {
        l=i+1;
        s[i]=add;
    }
    else l=i;
    for (i=0; i<l; i++)
        t[l-1-i]=s[i]+'0';
    t[l]='\0';
}
```
### 精度计算——乘法（大数乘大数）

语法：
>mult(char a[],char b[],char s[]);

参数：
>a[]：被乘数，用字符串表示，位数不限
>
>b[]：乘数，用字符串表示，位数不限
>
>t[]：结果，用字符串表示

返回值：
>null
>
>注意： 空间复杂度为 o(n^2)
>
>需要 string.h




