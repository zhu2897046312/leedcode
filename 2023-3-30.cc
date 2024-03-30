#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <map>
#include <climits> // For INT_MAX

using namespace std;



struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


namespace _1 {

//19. 删除链表的倒数第 N 个结点

/**
    L - n + 1
*/
class Solution {
public:
    static ListNode* removeNthFromEnd(ListNode* head, int n) {
        unordered_map<int, ListNode*> mp;
        ListNode* dummy = new ListNode(0, head);
        ListNode* tmp = dummy;
        int j = 0;
        while (tmp) {
            mp.insert({j++,tmp});
            tmp = tmp->next;
        }
        if(mp[mp.size() - 1 - n]){
            if(mp.count(mp.size() - n + 1)){
                mp[mp.size() - 1 - n]->next = mp[mp.size() - n + 1];
            }else{
                 mp[mp.size() - 1 - n]->next = nullptr;
            }
        }
        if(mp[mp.size() - n]){
            delete mp[mp.size() - n];
            mp[mp.size() - n] = nullptr; 
        }
        for(auto v : mp){
            if(v.second){
                cout << v.second->val;
            }
        }
        cout << endl;
        return dummy->next;
    }
};
}
//25. K 个一组翻转链表
/**   
  1 2 3 4 5         k = 2
  (0) |1 2| 3 4 5
    1. 先翻转 1 2
    2. 再让0接上 2 1

*/
namespace _2 {
class Solution {
public:
    // 翻转一个子链表，并且返回新的头与尾
   static pair<ListNode*, ListNode*> myReverse(ListNode* head, ListNode* tail) {
        ListNode* prev = tail->next;
        ListNode* p = head;
        while (prev != tail) {
            ListNode* nex = p->next;
            p->next = prev;
            prev = p;
            p = nex;
        }
        return {tail, head};
    }

   static ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* hair = new ListNode(0);
        hair->next = head;
        ListNode* pre = hair;

        while (head) {
            ListNode* tail = pre;
            // 查看剩余部分长度是否大于等于 k
            for (int i = 0; i < k; ++i) {
                tail = tail->next;
                if (!tail) {
                    return hair->next;
                }
            }
            ListNode* nex = tail->next;
            tie(head, tail) = myReverse(head, tail);
            pre->next = head;
            tail->next = nex;
            pre = tail;
            head = tail->next;
        }

        return hair->next;
    }
};

}


// -4 -1 -1 0 1 2
int main(){
    ListNode* head = new ListNode(0, nullptr);
    ListNode* tmp = head;
    int i = 1;
    while(tmp && i < 10){
        tmp->next = new ListNode( i, nullptr);
        tmp = tmp->next;
        i++;
    }

    auto y =_1::Solution::removeNthFromEnd(head, 2);
    while(y){
        cout << y->val << " ";
        y = y->next;
    }
    cout << endl;

    auto x = _2::Solution::reverseKGroup(head,2);

   
    return 0;
}