/*
 * @Date: 2021-11-20 23:14:37
 * @LastEditors: kafier
 * @LastEditTime: 2021-11-21 08:16:04
 */
#include <stdio.h>
#include <iostream>
using namespace std;
union test
{
    int a;
    char b;
};

int endian_test(void)
{
    union test t1;
    t1.a = 1;
    return t1.b;
}

int main(void)
{
    int i = endian_test();
    if(i == 1)// 如果为1， char型变量在低位， 这样地址才是相同的 
        cout << "is littel endian" << endl;
    else    // 如果为其他， 则在高位
        cout << "is big endian" << endl;
}
// Union成员本身被存放到相同的内存空间中（即共享内存） union联合体占用内存大小等于该union的最大成员的大小， 在一个char性和int性的变量的union中可以通过取值判断出主机字节序
// 将一个char 型变量和一个int型变量放在同一内存开始地址处， 读取整型数据， 根据数据值可以判断出char型变量在int型变量的高位还是低位。 
// 小端： 将低序字节存储在起始地址， 则成为小端字节序。 网络字节序是大端。 主机字节序是小端。 