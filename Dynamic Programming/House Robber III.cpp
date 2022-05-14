class Solution {  
public:
  
// M-I 
    int rob(TreeNode* root) {
        int l, r;
        return tryRob(root, l, r);
    }
  
    int tryRob(TreeNode* root, int& l, int& r) {
        if (!root)
            return 0;
            
        int ll = 0, lr = 0, rl = 0, rr = 0;
        l = tryRob(root->left, ll, lr);
        r = tryRob(root->right, rl, rr);
        
        return max(root->val + ll + lr + rl + rr, l + r);
    }
    
// M-II
     int rob(TreeNode* root) {
        pair<int,int> ans = helper(root);
        return max(ans.first, ans.second);
    }
  
    pair<int,int> helper(TreeNode* root){
        if(!root) return {0,0};
        if(!root->left && !root->right) return {root->val,0};
        
        pair<int,int> left = helper(root->left);
        pair<int,int> right = helper(root->right);
        pair<int,int> p;
        
        p.first = root->val + left.second + right.second;
        p.second = max(left.first,left.second) + max(right.first,right.second);
        
        return p;
    }
};
