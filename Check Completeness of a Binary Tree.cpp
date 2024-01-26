//approach 

//basically idea for bfs is that you keep track of null value when it is getting
//if it is getting in past before any value being insert that mean it is wrong you return false

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool past = false; //kya pehle null dekha h 

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node == NULL){
                past = true;
            }else{
                if(past == true){
                    return false;
                }
                q.push(node->left);
                q.push(node->right);
            }
        }
        return true;

    }
};


//dfs if parent has on index on i the lf child 2i and 2i+1;
// if index reach in array is out of no of node then it is not a binary tree
//null wla case zero bhejhana jruri hai kynki wha pe index nhi dena h mujhe  like left most jaung wha
//null aaya toh wha nhi dena mujhe check krna h wha jha ek root h wha index glt h ya nhi bs whi check
//krna h bs

class Solution {
public:
    int count(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        return  1 + count(root->left) + count(root->right);
    }
    bool dfs(TreeNode*root , int &totalNode ,int i){
        if(root == NULL)return true;

        if(i > totalNode)return false;

        return dfs(root->left , totalNode, 2*i) && dfs(root->right, totalNode ,2*i+1);
    }
    bool isCompleteTree(TreeNode* root) {
        int totalNode = count(root);

        int i = 1; //root ka index i rkhenge

        return dfs(root, totalNode , i);
    }
};