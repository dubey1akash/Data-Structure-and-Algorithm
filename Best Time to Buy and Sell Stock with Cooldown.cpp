//approach

class Solution {
public:
    int t[5001][2];
    int solve(vector<int>& prices, int day, int n, bool buy){
        if(day >= n)
           return 0;

        if(t[day][buy] != -1){
            return t[day][buy];
        }
        int profit = 0;

        if(buy){//buy
            int take = solve(prices, day+1, n, false) - prices[day];


            int not_take = solve(prices, day+1, n, true);

            profit = max({profit, take, not_take});
        }
        else{
            int sell = prices[day] + solve(prices, day+2, n, true);

            int not_sell = solve(prices, day+1, n, false);

            profit = max({profit, sell, not_sell});
        }
        return t[day][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        memset(t, -1, sizeof(t));

        bool buy = true;

        return solve(prices, 0, n, buy);
    }
};


//Approach-2 (DP : O(n^2))
class Solution {
public:
    int maxP(vector<int>& prices, int& n) {
        if(n == 0 || n == 1)
            return 0;
        vector<int> t(n, 0);
        
        //t[i] = max profit at the end of ith day
        t[0] = 0; //no profit on 0th day
        t[1] = max(prices[1] - prices[0], 0); // max(bought_day_0 and sell_day_1, 0);
        
        /*  
            Let's analyse ith day, i.e. t[i] :
            i-th day can be :
            - BUY DAY   -> NO, because why would someone buy on last day
            
            - COOL DOWN -> YES, in that case, max-profit will be previsou's day profit (t[i] = t[i-1])
            
            - SELL DAY  -> If we choose to sell today, We will have to select the best buy day from j = 0 to j = (i-1)
                          So, profit = prices[j] - prices[i]; //i.e. we bought on day-j and sell on day-i
                          But, what about previous-profit of j i.e. t[j]. We need to consider that as well to find whole
                          maximum profit.
                          So, for that let's look previously to j :
                          Look at (j-1) -> It can't be buy-day, becuse we are already buying on jth day
                                        -> It can't be sell-day because, after you sell your stock on (j-1)th day, you cannot buy stock on the next day i.e. (jth) day (i.e., cooldown one day).
                                        -> It can only be cool-down day. max profit till (j-1)th day will be
                                            equal to its privous profit i.e. t[j-2]
                                            
                        So, profit at day i = prices[j] - prices[i] + t[j-2];
                          
        */
        
        for(int i = 2; i<n; i++) {
            t[i] = t[i-1]; //cool down
            
            //find best buy day from j  = 0 to i-1
            for(int j = 0; j<=i-1; j++) {
                
                int prev_profit = j>=2 ? t[j-2] : 0;
                
                t[i] = max(t[i], prices[i] - prices[j] + prev_profit);
            }
        }
        
        return t[n-1];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return maxP(prices, n);
    }
};