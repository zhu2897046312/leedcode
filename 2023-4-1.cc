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

//238. 除自身以外数组的乘积

/**
    1,2,3,4

L   1,1,2,6
R  24,12,4,1

ans[i] = l * r

*/
class Solution {
public:
    static vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> left(len,0) , right(len,0);
        vector<int> ans(len,0);
        left[0] = 1;
        right[len - 1] = 1;
        for(int i = 1; i < len; ++i){
            left[i] = left[i - 1] * nums[i - 1];
        }
        for(int i = len - 2; i >= 0; --i){
            right[i] = right[i + 1] * nums[i + 1];
        }

        for(int i = 0; i < len; ++i){
            ans[i] = left[i] * right[i];
        }
        return ans;
    }
};
}
//41. 缺失的第一个正数
/**   
  1. 先排序
  2. 找 > 0 的index
  3. 判断
*/
namespace _2 {
class Solution {
public:
    static int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int num = 1;
        int index = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] > 0){
                index = i;
                break;
            }
        }

        for(int i = index; i < nums.size(); ++i){
            if(nums[i] == num){
                num++;
            }else if(nums[i] > num){
                return num;
            }
        }

        return num;
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
   auto y =_1::Solution::productExceptSelf(vec);

    auto x = _2::Solution::firstMissingPositive(vec);

    auto z = _3::Solution::searchMatrix(arr,5);
    return 0;
}