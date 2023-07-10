class Solution {
public:
    
    // tabulation 
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> cur(2 , 0 ) , prev(2 , 0);
        prev[1] = prev[0] = 0 ;
        for(int ind = n-1 ; ind >= 0 ; ind-- )
        {
            for(int buy = 0 ; buy <= 1 ; buy++)
            {
                    int profit = 0 ;
                    if(buy)             // if u can buy 
                    {
                        profit = max((-prices[ind] + prev[0]) ,  // decided to buy
                                      (0 +  prev[1]));             // didnt buy this time
                    }
                    else                // you cant buy 
                    {
                        profit = max(prices[ind] +  prev[1] , // decided to sell
                                    0 + prev[0]);  // not sell
                    }
                cur[buy] = profit ;
            } 
            prev = cur ;
        }
        return prev[1];
    }
};