#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <map>
#include <climits> // For INT_MAX

using namespace std;
namespace _1 {
//最大子数组和

/**
    nums  i
 -2,1,-3,4,-1,2,1,-5,4
 -2,1,-2,4,3,5,6,1,5,
 pre
*/
class Solution {
public:
    static int maxSubArray(vector<int>& nums) {
        int pre = 0;
        int ansMax = nums[0];
        for(auto & x : nums){
            
            pre = max(pre + x, x);
            cout << pre << ",";
            ansMax = max(ansMax, pre);
        }
        cout << endl;
        return ansMax;
    }
};
}
//合并区间
/**
    i   j 
    0   1   [1,3]   [2,6] j++  
    0   2   [1,3]   [8,10]  --> 合并    [1,3]   [2,6]
    2   3   [8,10]  [15,18] 不用合并
    3   4   [15,18] nil 不用合并
*/
namespace _2 {
class Solution {
public:
    static vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        for(int i = 0; i < intervals.size();){
            int t = intervals[i][1];
            int j = i + 1;
            while(j < intervals.size() && t >= intervals[j][0]){
                t = max(t, intervals[j][1]);
                j++;
            }

            result.push_back({intervals[i][0], t});
            i = j;
        }

        return result;
    }
};

}

// 旋转数组
/**
    i
    0 1 2 3 4 5 6
    --------------
    3 4 5 6 0 1 2 
    (i + k) % n
*/
namespace _3 {
class Solution {
public:
    static void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(nums);
        for(int i = 0; i < n; ++i){
           ans[(i + k) % n] = nums[i];
           cout << ((i + k) % n) << " ";
        }
        cout << endl;
       nums.assign(ans.begin(), ans.end());
    }
};

}

// -4 -1 -1 0 1 2
int main(){
    vector<int> vec({-2,1,-3,4,-1,2,1,-5,4});
    _1::Solution::maxSubArray(vec);

    vector<vector<int>> vec_2({
        vector<int>(1,3),
        vector<int>(2,6),
        vector<int>(8,10),
        vector<int>(15,18),
        });
    auto tmp = _2::Solution::merge(vec_2);
    
    vector<int> nums({1,2,3,4,5,6,7});
    _3::Solution::rotate(nums,3);
    return 0;
}