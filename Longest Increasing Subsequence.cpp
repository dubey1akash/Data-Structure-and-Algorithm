//approach is like literally dp problem 

class Solution {
public:
    int n;
    int t[2501][2501];
    int solve(vector<int>&nums, int i, int P){
        if(i >= n){
            return 0;
        }
        if(P != -1 && t[i][P] != -1)return t[i][P];
        int take = 0;
        if(P == -1 || nums[i] > nums[P])take = 1 + solve(nums, i+1, i);

        int skip = solve(nums, i+1, P );
        if(P != -1)
            t[i][P] = max(take, skip);
        return  max(skip, take);
    }
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        memset(t, -1, sizeof(t) );


        return solve(nums, 0, -1);
    }
};

//bottom up bro 

class Solution {
public:
   
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> t(n, 1);
        //t[i] = lis ending at ith index

        int maxLis =1;
         for(int i = 0; i<n; i++){
             for(int j = 0; j<i; j++){
                 if(nums[j] < nums[i]){
                     t[i] = max(t[i], t[j]+1);
                     maxLis = max(maxLis, t[i]);
                 }
             }
        }
         return maxLis;

    }
};


