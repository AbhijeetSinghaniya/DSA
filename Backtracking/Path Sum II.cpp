class Solution {
public:
    
    vector<vector<int>> ans;
    
    void solve(TreeNode* root,int sum,int target,vector<int>& temp){
        if(!root) return;
        
        if(!root->left && !root->right){
            sum += root->val;
            if(sum == target){
                temp.push_back(root->val);
                ans.push_back(temp);
                temp.pop_back();
            }
            return;
        }
        
        sum += root->val;
        temp.push_back(root->val);
        solve(root->left,sum,target,temp);
        solve(root->right,sum,target,temp);
        sum -= root->val;
        temp.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        if(!root) return ans;
        int sum = 0;
        vector<int> temp;
        solve(root,sum,target,temp);
        return ans;
    }
};
