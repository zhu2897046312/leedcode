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
//和为k的子数组
class Solution {
public:
    static int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int sum = 0;
        int ret = 0;
        mp[0] = 1;
        for(int i = 0;i < nums.size(); ++i)
        {
            sum += nums[i];
            if(mp.count(sum - k)){
                ret += mp[sum - k];
            }
            mp[sum]++;
        }

        return ret;
    }
};
}
//接雨水
namespace _2 {
class Solution {
public:
    static int trap(vector<int>& height) {
        int result = 0;
        stack<int> st;

        for(int i = 0; i < height.size(); ++i){
            while(!st.empty() && height[st.top()] < height[i]){
                int cur = st.top();
                st.pop();
                if (st.empty()) break;
                int l = st.top();
                int r = i;
                int h = min(height[l], height[r]) - height[cur];
                result += (r - l -1) * h;
            }
            st.push(i);
        }
        return result;
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
    vector<int> vec({1,1,1});
    _1::Solution::subarraySum(vec,2);

    vector<int> vec_2({0,1,0,2,1,0,1,3,2,1,2,1});
    auto tmp = _2::Solution::trap(vec_2);
    
    string s("baa");
    string p("aa");
    auto num = _3::Solution::findAnagrams(s,p);
    return 0;
}