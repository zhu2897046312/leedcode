#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <map>
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
//接雨水
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
namespace _3 {
class Solution {
public:
    static vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        unordered_map<char, int> hashp, hashs;
        int n = s.size();
        //记录p串各字符出现次数
        for(int i = 0; i < p.size(); i++){
            hashp[p[i]]++;
        }
        int left = 0, right = 0;
        int cnt = 0;
        while(right < n){
            //扩展窗口
            char c = s[right];
            hashs[c]++;
            cnt++;
            right++;
            //调整窗口
            while(hashs[c] > hashp[c]){
                hashs[s[left]]--;
                left++;
                cnt--;
            }
            //记录答案
            if(cnt == p.size()){
                res.push_back(left);
            }
        }
        return res;
    }
};

}

// -4 -1 -1 0 1 2
int main(){
    vector<int> vec({1,0,1,1});
    _1::Solution::containsNearbyDuplicate(vec,1);

    vector<int> vec_2({1,3,-1,-3,5,3,6,7});
    auto tmp = _2::Solution::maxSlidingWindow(vec_2,3);
    
    string s("baa");
    string p("aa");
    auto num = _3::Solution::findAnagrams(s,p);
    return 0;
}