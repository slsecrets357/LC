struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int traversal(TreeNode* cur) {
        
    }
    int minCameraCover(TreeNode* root) {
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        if(left == nullptr && right == nullptr) {
            return 0;
        } else if(left == nullptr) {
            return minCameraCover(right) + 0.5;
        } else if(right == nullptr) {
            return minCameraCover(left) + 0.5;
        } else {
            int minLeft = minCameraCover(left);
            int minRight = minCameraCover(right);
            return 1+minLeft+minRight;
        }
    }
};