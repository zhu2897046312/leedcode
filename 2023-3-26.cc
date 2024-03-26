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
//存在重复元素 II
class Solution {
public:
    static bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        bool flag = false;
        for(int i = 0; i < nums.size(); i++){
            int num = nums[i];
            if(mp.count(num) && (i - mp[num]) <= k){
               flag = true;
            }
            mp[num] = i;
        }
        return flag;
    }
};
}
//滑动窗口最大值
namespace _2 {
class Solution {
public:
    static vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < k; ++i) {
            q.emplace(nums[i], i);
        }
        vector<int> ans = {q.top().first};
        for (int i = k; i < n; ++i) {
            q.emplace(nums[i], i);
            while (q.top().second <= i - k) {
                q.pop();
            }
            ans.push_back(q.top().first);
        }
        return ans;
    }
};

}

// 最小覆盖子串  --- 难
namespace _3 {
class Solution {
public:
    static   string minWindow(string s, string t) {
        //设置哈希表用来存放窗口值以及进行比较的值
        unordered_map<char, int> need, win;
        //将我们所需要的值加入到哈希表（需要进行比较的值）
        for (auto &i : t) ++need[i];
        int left = 0, right = 0, count = 0, len = INT_MAX, start = 0;
        //开始对窗口进行处理
        while (right < s.size()) {
            //如果我们此时字符串中的元素在我们的需要窗口中的话
            //我们就需要扩充窗口
            if (need.count(s[right])) {
                //此时进行扩充窗口
                ++win[s[right]];
                //运用count来进行确保我们此时的窗口值完全覆盖了我们需要的子串
                if (win[s[right]] == need[s[right]]) {
                    ++count;
                }
            }
            //如果此时的窗口值完全覆盖了我们需要的子串，就要进行缩小窗口的操作
            while (count == need.size()) {
                //这里是进行更新我们的最小子串
                if (len > right - left + 1) {
                    start = left;
                    len = right - left + 1;
                }
                //这里开始对窗口进行处理
                //如果此时的窗口左侧的值在我们的哈希表中的话
                //就要进行判断是否要对count进行处理
                if (need.find(s[left]) != need.end()) {
                    //如果此时的窗口左侧的值在哈希表中且数量和哈希表中的数量一致
                    //就对count计数位进行减一操作
                    if (need[s[left]] == win[s[left]]) {
                        --count;
                    }
                    //将窗口左侧的值进行减一，缩小窗口
                    --win[s[left]];
                }
                ++left;
            }
            ++right;
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};

}

// -4 -1 -1 0 1 2
int main(){
    vector<int> vec({1,0,1,1});
    _1::Solution::containsNearbyDuplicate(vec,1);

    vector<int> vec_2({1,3,-1,-3,5,3,6,7});
    auto tmp = _2::Solution::maxSlidingWindow(vec_2,3);
    
    string s("ADOBECODEBANC");
    string p("ABC");
    auto num = _3::Solution::minWindow(s,p);
    return 0;
}