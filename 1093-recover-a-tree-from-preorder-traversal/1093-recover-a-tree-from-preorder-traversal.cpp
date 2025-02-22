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
    TreeNode* recoverFromPreorder(string traversal) {
        stack<TreeNode*> st;
        int i = 0, n = traversal.size();
        
        while (i < n) {
            int depth = 0;
            while (i < n && traversal[i] == '-') { // Count dashes to determine depth
                depth++;
                i++;
            }
            
            int num = 0;
            while (i < n && isdigit(traversal[i])) { // Extract number value
                num = num * 10 + (traversal[i] - '0');
                i++;
            }
            
            TreeNode* node = new TreeNode(num);
            
            while (st.size() > depth) // Move up the tree if needed
                st.pop();
            
            if (!st.empty()) {
                if (!st.top()->left) 
                    st.top()->left = node;
                else 
                    st.top()->right = node;
            }
            
            st.push(node);
        }
        
        while (st.size() > 1) 
            st.pop();
        
        return st.top();
    }
};
