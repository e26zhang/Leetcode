class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size() == 0) { // base case: empty vector
            return nullptr;
        }
        
        if(nums.size() == 1) { // base case: 1 element vector
            return new TreeNode(nums[0]);
        }
        
        vector<int> left, right;
        bool maxFound = false;
        int max = *max_element(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] == max) {
                maxFound = true;
            } else if(!maxFound) {
                left.push_back(nums[i]);
            } else {
                right.push_back(nums[i]);
            }
        }
        
        TreeNode *t = new TreeNode(max);
        t->left = constructMaximumBinaryTree(left);
        t->right = constructMaximumBinaryTree(right);
        
        return t;
    }
};