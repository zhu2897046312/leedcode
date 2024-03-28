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
//73. 矩阵置零

/**
    rows[i] = low[j] = 1;   标记  
*/
class Solution {
public:
    static void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> rows(m) , low(n);

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; ++j){
                if(!matrix[i][j]){
                    rows[i] = low[j] = 1;
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; ++j){
                if(rows[i] || low[j]){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
}
//54. 螺旋矩阵
/**   
   1,2,3       
   4,5,6
   7,8,9

   //上 右 下 左

    // 上                               1
    up = 0  left++   1,2,3===>result  up++
    //右                                1
    right = 2 up++  6,9===>result   right--
    //下
    down = 2 right-- 8,7===>result  down--
    //左
    left = 0 down-- 4,5===>result   left++
*/
namespace _2 {
class Solution {
public:
    static vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // 上 右 下 左
        vector<int> result;
        int up = 0;
        int down = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;
        while(true){
            // 上
            for(int i = left; i <= right; ++i){
                result.push_back(matrix[up][i]);
            }
            if(++up > down){
                break;
            }
            //右
            for(int i = up; i <= down; ++i){
                result.push_back(matrix[i][right]);
            }
            if (--right < left ){
                break;
            }
            //下
            for(int i = right; i >= left; --i){
                result.push_back(matrix[down][i]);
            }
            if (--down < up ){
                break;
            }
            //左
            for(int i = down; i >= up; --i){
                result.push_back(matrix[i][left]);
            }
            if (++left > right ){
                break;
            }
        }
        return result;
    }
};

}

// 48. 旋转图像
/**
    前
  (0,0)  (0,1)  (0,2)
   1    , 2     , 3    
  (1,0)  (1,1)  (1,2)
   4    , 5     , 6
  (2,0)  (2,1)  (2,2)
   7    , 8     , 9

   
    第一行 第xx个 对应 倒数第一列 第xx个
    第二行 第xx个 对应 倒数第二列 第xx个
    第三行 第xx个 对应 倒数第三列 第xx个
    后                 
  (0,0)  (0,1)  (0,2)
   7    , 4     , 1
  (1,0)  (1,1)  (1,2)
   8    , 5     , 2
  (2,0)  (2,1)  (2,2)
   9    , 6     , 3
*/
namespace _3 {
class Solution {
public:
    static void rotate(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> rows(m), lows(n);

        vector<vector<int>> result(n, std::vector<int>(m, 0));
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                result[j][n -i - 1] = matrix[i][j];
            }
        }
        matrix.assign(result.begin(),result.end());
    }
};

}

// -4 -1 -1 0 1 2
int main(){
    vector<vector<int>> vec({
        {1,1,1},
        {1,0,1},
        {1,1,1}
        });
    _1::Solution::setZeroes(vec);

    vector<vector<int>> vec_2({
        vector<int>({1,2,3}),
        vector<int>({4,5,6}),
        vector<int>({7,8,9}),
        });
    auto tmp = _2::Solution::spiralOrder(vec_2);
    
    vector<vector<int>> nums({
        vector<int>({1,2,3}),
        vector<int>({4,5,6}),
        vector<int>({7,8,9}),
        });
    _3::Solution::rotate(nums);
    return 0;
}