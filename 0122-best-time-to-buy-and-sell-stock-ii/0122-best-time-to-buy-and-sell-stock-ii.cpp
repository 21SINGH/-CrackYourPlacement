class Solution {
public:
    
    int f(int ind , int buy , vector<int>& prices , int n , vector<vector<int>>& dp)
    {
        if(ind == n )
            return 0 ;
        int profit = 0 ;
        if(dp[ind][buy] != -1)
            return dp[ind][buy];
        if(buy)             // if u can buy 
        {
            profit = max((-prices[ind] + f(ind+1 , 0 , prices , n , dp)) ,  // decided to buy
                          (0 + f(ind+1 , 1 , prices , n , dp )));             // didnt buy this time
        }
        else                // you cant buy 
        {
            profit = max(prices[ind] + f(ind+1 , 1 , prices , n ,dp) , // decided to sell
                        0 + f(ind+1 , 0, prices , n , dp));  // not sell
        }
        return dp[ind][buy]=profit ;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size() , vector<int>(2 , -1));
        return f(0 , 1 , prices , prices.size() , dp);
    }
};