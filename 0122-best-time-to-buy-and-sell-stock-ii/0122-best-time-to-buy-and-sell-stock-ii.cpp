class Solution {
public:
    
    // tabulation 
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1 , vector<int>(2 , 0));
        dp[n][0] = dp[n][1] = 0 ;   // cant do anything on alst index 
        
        for(int ind = n-1 ; ind >= 0 ; ind-- )
        {
            for(int buy = 0 ; buy <= 1 ; buy++)
            {
                    int profit = 0 ;
                    if(buy)             // if u can buy 
                    {
                        profit = max((-prices[ind] + dp[ind+1][0]) ,  // decided to buy
                                      (0 +  dp[ind+1][1]));             // didnt buy this time
                    }
                    else                // you cant buy 
                    {
                        profit = max(prices[ind] +  dp[ind+1][1] , // decided to sell
                                    0 +  dp[ind+1][0]);  // not sell
                    }
                dp[ind][buy] = profit ;
            } 
        }
        return dp[0][1];
    }
};