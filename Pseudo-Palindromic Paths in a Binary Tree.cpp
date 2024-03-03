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
    int result = 0;
    void solve(TreeNode * root , vector<int> & count){
        if(root == NULL){
            return;
        }
        count[root->val]++;
        if(root->left == NULL && root->right == NULL){
            int oddfreq = 0;
            for(int i =1; i<=9; i++){
                if(count[i]%2 !=0){
                    oddfreq++;
                }
            }
            if(oddfreq <= 1){
                result+=1;
            }
        }
        solve(root->left, count);
        solve(root->right, count);
        count[root->val]--;

    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> count(10, 0);

        solve(root, count);
        return result;
    }
};


///
class Solution {
public:
    int result = 0;
    
    void solve(TreeNode* root, int temp) {
        if(root != NULL) {
            
            temp = temp ^ (1 << root->val);
            
            if(root->left == NULL && root->right == NULL) {
                if((temp & (temp - 1)) == 0) { //Make sure to put (temp & (temp - 1)) entirely in bracket because precedence of == is high
                    result++;
                }
            }
            
            
            solve(root->left, temp);
            solve(root->right, temp);


        }
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {

        solve(root, 0);
        return result;
    }
};



