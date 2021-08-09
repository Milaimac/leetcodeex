#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<tuple> 
#include<queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};