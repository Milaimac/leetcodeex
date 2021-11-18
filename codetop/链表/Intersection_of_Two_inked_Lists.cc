/*
 * @Date: 2021-11-18 22:31:17
 * @LastEditors: kafier
 * @LastEditTime: 2021-11-18 23:51:38
 */
#include <stdio.h>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /**
     * @description: 
     * 需要判断是否有相交节点。  使用 双指针的做法。 
     * 1. 判断两个链表是否其中一个为空， 如果一个为空， 或者两个都为空， 都是返回NULL
     * 2. 如果两个长度相等， 以同个时间进行遍历， 必然能够遇到相交点。
     * 3. 如果两个长度不相等， 当先遍历到终点，跳到另一个链表的起点。 第二次遍历就能遇到相交点。 
     * 4. 原理： 两个链表的相同部分为C长度， headA 不相交（独立） 的为A 长度， headB为B长度
     *      通过交换， 最终遍历的节点都是 A+B+C ， 那么二者必会在第二次遍历的时候相遇。
     * 
     * @param {ListNode} *headA
     * @param {ListNode} *headB
     * @return {*}
     * 
     * 
     */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL)
        {
            return NULL;
        }
        ListNode *pa = headA; 
        ListNode *pb = headB;
        while(pa != pb)
        {
            pa = pa == NULL ? headB : pa->next;
            pb = pb == NULL ? headA : pb->next;
        }

        return pa;
    }
};