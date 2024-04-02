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

//148. 排序链表

/**
    1,2,3,4

L   1,1,2,6
R  24,12,4,1

ans[i] = l * r

*/
class Solution {
public:
    static ListNode* sortList(ListNode* head) {
       ListNode*result = head;
       ListNode* tmp = head;
       vector<int> vec;
       while(tmp){
            vec.push_back(tmp->val);
            tmp = tmp->next;
       }

        sort(vec.begin(), vec.end());
       for(auto & v : vec){
            result->val = v;
            result = result->next;
       }

       return head;
    }
};
}
//35. 搜索插入位置
/**   
  1. 先排序
  2. 找 > 0 的index
  3. 判断
*/
namespace _2 {
class Solution {
public:
    static int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int middle = 0;
        while(left <= right){
            middle = (right - left) / 2 + left;
            if(nums[middle] < target){
                left = middle + 1;
            }else{
                right = middle - 1;
            }
        }
        return left;
    }
};

}

//240. 搜索二维矩阵 II
/**
   对每行都使用二分搜索
*/
namespace _3 {
class Solution {
public:
    static bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (const auto& row: matrix) {
            auto it = lower_bound(row.begin(), row.end(), target);
            if (it != row.end() && *it == target) {
                return true;
            }
        }
        return false;
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
    vector<int> vec({1,2,3,4});
    vector<vector<int>> arr(
        {
            {1,4,7,11,15},
            {2,5,8,12,19},
            {3,6,9,16,22},
            {10,13,14,17,24},
            {18,21,23,26,30}
        }
    );
   auto y =_1::Solution::sortList(head);

    auto x = _2::Solution::searchInsert(vec,1);

    auto z = _3::Solution::searchMatrix(arr,5);
    return 0;
}