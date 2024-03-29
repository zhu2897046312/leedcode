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

//2. 两数相加

/**
    n1                      
    2   ,   4,  3           
    n2
    5   ,   6,  4

    cut = 0
    sum = n1 + n2 + cut val = sum % 10 cut = sum / 10
    7                   7               0
    10                  0               1
    8                   8               0
*/
class Solution {
public:
    static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = nullptr;
        ListNode* tmp = nullptr;
        int cut = 0;
        while(l1 || l2){
            int n1 = l1 ? l1->val: 0;
            int n2 = l2 ? l2->val: 0;

            int sum = n1 + n2 + cut;
            if(!result){
                tmp = result = new ListNode(sum % 10, nullptr);
            }else{
                tmp->next = new ListNode(sum % 10, nullptr);
                tmp = tmp->next;
            }
            cut = sum / 10;
            if(l1){
                l1 = l1->next;
            }
            if(l2){
                l2 = l2->next;
            }
        }
        if (cut > 0){
            tmp->next = new ListNode(cut, nullptr);
        }
        return result;
    }
};
}
//142. 环形链表 II
/**   
  hash_set 
*/
namespace _2 {
class Solution {
public:
    static ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode *> st;
        while (head != nullptr) {
            if (st.count(head)) {
                return head;
            }
            st.insert(head);
            head = head->next;
        }
        return nullptr;
    }
};

}

//24. 两两交换链表中的节点
/**
   1,2,3,4
   0 1,2,3,4

   0->next = 2
   1->next = 3
   2->next = 1

    temp->next = node2;
    node1->next = node2->next;
    node2->next = node1;
    temp = node1;
*/
namespace _3 {
class Solution {
public:
    static ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0, nullptr);
        dummyHead->next = head;
        ListNode* temp = dummyHead;
        while(temp->next && temp->next->next){
            ListNode* node1 = temp->next;
            ListNode* node2 = temp->next->next;
            temp->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            temp = node1;
        }

        ListNode* ans = dummyHead->next;
        delete dummyHead;
        return ans;
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

    auto y =_1::Solution::addTwoNumbers(head,head);

    auto x = _2::Solution::detectCycle(head);

    auto z = _3::Solution::swapPairs(head);
    return 0;
}