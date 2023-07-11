class Solution {
public:
    
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> after ( 2 ,vector<int>(k+1,0));
               
        vector<vector<int>> curr( 2 ,vector<int>(k+1,0));

        for(int ind = n-1 ; ind >=0 ; ind--)
        {
            for(int buy = 0 ; buy <= 1 ; buy++)
            {
                for(int cap = 1 ; cap <= k ; cap++) // value for every cap[0] is going to be 0 
                {
                    if(buy)
                    {
                        after[buy][cap] = max((-prices[ind] + after[0][cap]),
                                        (0 + after[1][cap])); 
                    }
                    else
                    {
                        after[buy][cap] = max((+prices[ind] + after[1][cap-1]),  
                                        (0 + after[0][cap]));   
                    }
                 }
                 curr = after ;
            }
        }

        return curr[1][k] ;
    }
};