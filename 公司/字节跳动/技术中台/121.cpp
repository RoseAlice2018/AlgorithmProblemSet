class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int min_price = __INT_MAX__;
       int max_value = 0;
       for(int i = 0;i<prices.size();i++)
       {
           if(min_price>prices[i])
           {
               min_price=prices[i];
           }
           if(prices[i]-min_price>max_value)
           {
               max_value=prices[i]-min_price;
           }
       } 
       return max_value;
    }
};