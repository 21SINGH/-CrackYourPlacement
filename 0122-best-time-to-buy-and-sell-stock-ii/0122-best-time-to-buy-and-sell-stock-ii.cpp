class Solution {
public:
    
    // tabulation 
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> cur(2 , 0 ) , next(2 , 0);
        next[1] = next[0] = 0 ;
        for(int ind = n-1 ; ind >= 0 ; ind-- )
        {
            for(int buy = 0 ; buy <= 1 ; buy++)
            {
                    int profit = 0 ;
                    if(buy)             // if u can buy 
                    {
                        profit = max((-prices[ind] + next[0]) ,  // decided to buy
                                      (0 +  next[1]));             // didnt buy this time
                    }
                    else                // you cant buy 
                    {
                        profit = max(prices[ind] +  next[1] , // decided to sell
                                    0 + next[0]);  // not sell
                    }
                cur[buy] = profit ;
            } 
            next = cur ;
        }
        return next[1];
    }
};