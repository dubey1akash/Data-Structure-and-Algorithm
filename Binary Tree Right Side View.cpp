//approach

//using bfs here things is  this whenever you travel using bfs(level order traversal )then
//last element is rightmost so just need to store that one in queue last one is the last stored
//element in queue 

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {

        if(root==NULL){
            return {};
        }
        vector<int>ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            TreeNode* node;
            while(n--){
                node=q.front();
                q.pop();
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
            }
            ans.push_back(node->val);
        }
        return ans;
    }
};


// using dfs here you need to keep track 
//level which has how many element as compared to level and going first right 

class Solution {
public:
   void preorder(TreeNode*root, int level ,vector<int>&res){
       if(root == NULL ){
           return;
       }
       if(res.size() < level){
           res.push_back(root->val);
       }
       preorder(root->right, level+1 , res);
       preorder(root->left , level+1 , res);
   }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        preorder(root , 1, res);
        return res;
    }
};