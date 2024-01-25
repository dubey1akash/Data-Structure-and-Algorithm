//approach 

//lca from down for both the point which is first common ancestor 
//from bottom to up 

//also thinking how do we pass that is mind game basically return case what should be 


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        }
        if(root == p || root == q){
            return root;
        }

        //left side sey leftn nikal lo
        TreeNode* leftN = lowestCommonAncestor(root->left , p ,q);
        TreeNode* rightN = lowestCommonAncestor(root->right , p ,q);

        if(leftN != NULL && rightN != NULL){
            return root;
        }
        if(leftN != NULL)return leftN;

        return rightN;

    }
};