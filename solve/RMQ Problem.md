# RMQ 问题及解决算法

## RMQ 问题

RMQ 问题，即区间最值查询，是在长度为 N 的序列中求出其连续的子序列中最大/最小值的问题。

## ST 算法

### 算法介绍

ST 算法适用于解决 RMQ 问题，是一个较长时间预处理，（时间复杂度为 O(NlogN)），在 O(1) 的时间内回答每个查询的算法。

### 算法思想及类型

算法思想为二分，将序列经过多次二分使最终区间为一个单位，类似线段树，本质为动态规划。

实现顺序为：

1. 区间大小为单位大小，计算出每个单位中最大/最小值（即为本身）

2. 逐渐增大区间大小（每次乘二），利用其两个子连续区间动态规划出这次计算的区间的最大/最小值

如图

![graph.png](https://raw.githubusercontent.com/billchenchina/cppcodes/master/solve/RMQ%20Problem/graph.png)

(Thanks to [Ferric](https://ferric.cf) and Graphviz)

### 代码实现

(from [https://www.topcoder.com/community/data-science/data-science-tutorials/range-minimum-query-and-lowest-common-ancestor/](https://www.topcoder.com/community/data-science/data-science-tutorials/range-minimum-query-and-lowest-common-ancestor/) )


```cpp
void process2(int M[MAXN][MAXN], int A[MAXN], int N) {
    int i, j;
    //initialize M for the intervals with length 1
    for (i = 0; i < N; i++)
        M[i][0] = i;
    //compute values from smaller to bigger intervals
    for (j = 1; 1 << j <= N; j++)
        for (i = 0; i + (1 << j) - 1 < N; i++)
            if (A[M[i][j - 1]] < A[M[i + (1 << (j - 1))][j - 1]])
                M[i][j] = M[i][j - 1];
            else
                M[i][j] = M[i + (1 << (j - 1))][j - 1];
}
```