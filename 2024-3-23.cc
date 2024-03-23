#include <iostream>
#include <queue>
using namespace std;
namespace day_3_23_1 {
class Solution {
public:
//对称二叉树  层序遍历
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };
    bool check(TreeNode *u, TreeNode *v) {
        std::queue <TreeNode*> q;
        q.push(u); q.push(v);
        while (!q.empty()) {
            u = q.front(); q.pop();
            v = q.front(); q.pop();
            if (!u && !v) continue;
            if ((!u || !v) || (u->val != v->val)) return false;

            q.push(u->left); 
            q.push(v->right);

            q.push(u->right); 
            q.push(v->left);
        }
        return true;
    }

    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }
};
namespace day_3_23_2 {
//二叉树层序遍历
class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };  
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == nullptr){
            return vector<vector<int>>({});
        }
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int cut = que.size();
            vector<int> tmp;
            while(cut > 0){
                TreeNode* rt = que.front();
                que.pop();
                if(rt){
                    tmp.push_back(rt->val);
                    if(rt->left){
                        que.push(rt->left);
                    }
                    if(rt->right){
                        que.push(rt->right);
                    }
                }
                cut -= 1;
            }
            result.push_back(tmp);
        }

        return result;
    }
};

}

namespace day_3_23_3 {

//二叉树直径  -- 深度搜索
class Solution {
public:
    struct TreeNode {   
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };  
    int ans = 0;
    int depth(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int l = depth(root->left);
        int r = depth(root->right);
        ans = max(ans,l + r + 1);
        return max(l, r) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 1;
        depth(root);
        return ans - 1;
    }
};

}

}

int main(){
    
    return 0;
}