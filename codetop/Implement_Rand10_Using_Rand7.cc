/*
 * @Date: 2021-12-01 14:58:12
 * @LastEditors: kafier
 * @LastEditTime: 2021-12-01 16:05:57
 */
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7
int rand7();
/**
 * @description: 
 * 使用拒绝采样的方法实现rand10()
 * 具体的生成方法有很多中， 我们可以利用两个rand7()相乘， 只取其中等概率的10个不同的数的组合即可
 * @param {*}
 * @return {*}
 */
class Solution {
public:
    int rand10() {
        int x = 0;
        do{
            x = (rand7() - 1) * 7 + rand7();
        }while( x > 40);
        return x % 10 +1;
    }
};
