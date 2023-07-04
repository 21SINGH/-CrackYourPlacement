class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minValue = INT_MAX;
        int maxValue = 0 ;
        
        for(int i = 0 ; i < prices.size() ;i++)
        {
            minValue = min(minValue , prices[i]);
            maxValue = max(maxValue , prices[i] - minValue);
        }
        
        return maxValue ;
    }
};