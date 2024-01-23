//approach 

//well you need to find you for a given root what possible could be left and right and
//then again call recursively when l > r then nothing is there for a specific root there it will come 
//null when recursion return tree will be formed 

class Solution {
public:
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int strt, int e, int &idx){
        if(strt > e) return NULL;
        int rootVal = preorder[idx];


        int i = strt;

        for(; i<=e; i++){
            if(inorder[i]==rootVal){
                break;
            }
        }
        idx++;
        TreeNode* root = new TreeNode(rootVal);
        root->left = solve(preorder, inorder, strt, i-1, idx);
        root->right = solve(preorder, inorder, i+1, e , idx);

        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int idx = 0;


        return solve(preorder,inorder , 0 , n-1,idx);
    }
};