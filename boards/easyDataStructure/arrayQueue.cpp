#include <iostream>

using namespace std;

int main(){
    // 定义队列
    int a[10000000];
    // 初始化指针
    int front_pointer=0;
    int end_pointer=0;
    // 向队尾插入数值
    a[end_pointer++]=3;
    int b;
    // 查看队头数值
    b=a[front_pointer];
    // 出队
    front_pointer++;
}
