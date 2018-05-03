class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len <=1)
            return 0;
        int count = 0, sum = 0, delta = 0;
        for(int i=0; i<len-1; ++i){
            if(prices[i+1]<prices[i])
                ++count;
            else{
                delta = prices[i+1] - prices[i];
                sum += delta;
            }
            if(count == len-1)
                return 0;
        }
        return sum;
    }
};