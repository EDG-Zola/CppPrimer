class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        //算出相邻元素的差值数组delta
        vector<int> delta;
        int len=prices.size();
        int count=0;
        //只有一个元素的情况
        if(len<=1)
            return 0;   
        //算出相邻元素的差值数组delta
        for(int i=0; i<len-1; ++i){
            //从大到小的情况
            if(prices[i+1] < prices[i])
                ++count;
            if(count == len-1)
                return 0;
            delta.push_back(prices[i+1] - prices[i]);
        }
        int lenDelta = delta.size();
        //只有两个元素，且第二个元素比第一个大的情况
        if(lenDelta == 1)
            return delta[0];
        //计算最大子数组
        int maxSum = delta[0], thisSum = delta[0];
        
        for(int i=1; i != lenDelta; ++i){
            if(thisSum < 0)
                thisSum = delta[i];
            else
                thisSum += delta[i];
            if(maxSum < thisSum)
                maxSum = thisSum;
        }
        return maxSum;
    }
};