/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class NodeValue{
    
    public:
    int sum, min,max;
    NodeValue(int min,int max,int sum){
        this->min = min;
        this->max = max;
        this->sum = sum;
    }
};

class Solution {
    int maxi =0;
public:
    NodeValue f(TreeNode* root){
        if(root == NULL){
            return NodeValue(INT_MAX, INT_MIN,0); // this is for leaf node 
        }

        auto left = f(root->left);
        auto right = f(root->right);
        // FOR BST
       if (root->val > left.max && root->val < right.min){
           maxi = max(maxi,left.sum + right.sum + root->val);
            return NodeValue( min(left.min,root->val), max(right.max,root->val), left.sum + right.sum + root->val);
        }

        // for not bst
        return NodeValue(INT_MIN,INT_MAX,max(0,max(left.sum,right.sum)));


    }
    int maxSumBST(TreeNode* root) {
        f(root);
        return maxi;
    }
};
