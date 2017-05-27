## NOIP2015 普及组第三题 sum 题解

看到这题第一想法就是暴力，于是就试了试。暴力就是两层循环，每次比较x与z的color。

总能过点分的吗 23333 好了40分

## 正解

正经点，这题是个前缀和，先扫一遍，把 color 和奇偶性相同的放到一起再说。

然后，在每组里可以用公式来算[图片] ( 先留个坑，公式以后再补上 )，**边算边求模**，以防爆 int。然后就很高兴的A了。

[sum.cpp](https://github.com/billchenchina/cppcodes/blob/master/NOIP/sum.cpp)

