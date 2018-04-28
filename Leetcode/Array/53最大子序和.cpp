class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //判断是否为空数组
        int len = nums.size();
        if(len == 0)
            return false;
        int maxSum = nums[0], thisSum = nums[0];
        for(int i=1; i != len; ++i){
            if(thisSum < 0)
                thisSum = nums[i];
            else
                thisSum += nums[i];
            if(maxSum < thisSum)
                maxSum = thisSum;
        }
        return maxSum;
    }
};

//BEST ANSWER
// static const auto _=[]()
// {
// 	ios::sync_with_stdio(false);
// 	std::cin.tie(0);
// 	return 0;
// }();

// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int l = nums.size();
//         int ans = nums[0],sum = nums[0];
//         for(int i  = 1;i < l;i++)
//         {
//         	sum = max(sum+nums[i],nums[i]);
//         	ans = max(sum,ans);
//         }
//         return ans;
//     }
// };