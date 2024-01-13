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
class Solution {
public:
    void parentFun(map<TreeNode*,TreeNode*>&parent, TreeNode* &root){
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            TreeNode* top = st.top();
            st.pop();
            if(top->left) {
                parent[top->left] = top;
                st.push(top->left);
            }
            if(top->right) {
                parent[top->right] = top;
                st.push(top->right);
            }
        }
    }

    void find(TreeNode* &start,TreeNode* &root, int s){
        if(root==NULL) return;

        if(root->val==s){
            start = root;
        }
        find(start,root->left,s);
        find(start,root->right,s);

    }
    int amountOfTime(TreeNode* root, int s) {
        map<TreeNode*,TreeNode*>parent;
        parentFun(parent,root);

        TreeNode* start;
        find(start,root,s);

        stack<pair<TreeNode*,int>> st;
        st.push({start,0});

        map<int,bool>vis;

        int ans =0;

        while(!st.empty()){

            auto top = st.top();
            st.pop();
            TreeNode* node = top.first;
            int dis = top.second;
            vis[node->val] = true;

            ans = max(ans,dis);

            if(node->left && vis.find(node->left->val)==vis.end()){
                st.push({node->left,dis+1});
            }
            if(node->right && vis.find(node->right->val)==vis.end()){
                st.push({node->right,dis+1});
            }
            if(parent.find(node)!=parent.end() && vis.find(parent[node]->val)==vis.end()){
                st.push({parent[node],dis+1});
            }
        }
        return ans;
    }
};
