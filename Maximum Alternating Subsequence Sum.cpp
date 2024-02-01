//approach

//well if you draw the tree you will realize when you are getting for minus and when plus 
//that way you can pass that value and also for subsequence you know that how things work take or don't take

class Solution {
public:
    int n;
    long long t[1000001][2];
    long long solve(int idx, vector<int>& nums, bool iseven) {
        
        if(idx >= n) {
            return 0;
        }
        if(t[idx][iseven] != -1)
            return t[idx][iseven];
        
        long long skip = solve(idx+1, nums, iseven);
        
        long long val = nums[idx];
        if(iseven == false) {
            val = -val;
        }
        
        long long take = solve(idx+1, nums, !iseven) + val;
        
        return t[idx][iseven] = max(skip, take);
        
    }
    
    long long maxAlternatingSum(vector<int>& nums) {
        n = nums.size();
        memset(t, -1, sizeof(t));
        return solve(0, nums, true);
    }
};

//what a depth of state knowledge

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        vector<vector<long>> t(n+1 , vector<long>(2, 0));
         
        for(int i=1; i<n+1; i++){

            //even length ka subsequ
            t[i][0] = max(t[i-1][1]-nums[i-1], t[i-1][0] );

            t[i][1] = max(t[i-1][0]+nums[i-1], t[i-1][1] );
        }

        return max(t[n][0], t[n][1]);

    }
};