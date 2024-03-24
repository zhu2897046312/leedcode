#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
namespace _1 {
class Solution {
public:
    static int maxArea(vector<int>& height) {
        int result = 0;
        // for(int i = 0; i < height.size() - 1; i++){
        //     for(int j = i + 1; j < height.size(); j++){
        //         int m = min(height[i], height[j]);
        //         int s = m* (j - i);
        //         result = max(result,s);
        //     }
        // }
        // return result;

        int l = 0;
        int r = height.size() - 1;
        while(l < r){
            int tmp = min(height[l], height[r]) * (r - l);
            result = max(tmp, result);
            if(height[l] <= height[r]){
                ++l;
            }else{
                --r;
            }
        }
        return result;
    }
};
}

namespace _2 {
class Solution {
public:
   static vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int l = i + 1;
            int r = n - 1;
            while(l < r){
                if(nums[i] + nums[l] + nums[r] < 0){
                    ++l;
                }else if(nums[i] + nums[l] + nums[r] > 0){
                    --r;
                }else{
                    result.push_back({nums[i], nums[l], nums[r]});
                    while (l+1 < n && nums[l] == nums[++l]);
                    while (r-1 > 0 && nums[r] == nums[--r]);
                }
            }
        }
        return result;
    }
};
}
namespace _3 {
class Solution {
public:
    static int lengthOfLongestSubstring(string s) {
        //哈希表记录元素最后出现的位置
        unordered_map<char, int> hash;
        int ans = 0, left = 0;
        int i;
        for(i = 0; i < s.length(); ++i){
            char cur = s[i];
            if(hash.count(cur)){
                ans = max(ans, i - left);
                left = max(left, hash[cur] + 1);
            }
            hash[cur] = i;
        }
        return max(ans, i - left);
    }
};
}

// -4 -1 -1 0 1 2
int main(){
    vector<int> vec({1,8,6,2,5,4,8,3,7});
    _1::Solution::maxArea(vec);

    vector<int> vec_2({-1,0,1,2,-1,-4});
    auto tmp = _2::Solution::threeSum(vec_2);
    
    string s("pwwkew");
    auto num = _3::Solution::lengthOfLongestSubstring(s);
    return 0;
}