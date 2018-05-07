// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         int len=nums.size();
//         if(len<=0)
//             return 0;
//         if(len==1)
//             return nums[0]+1;
//         sort(nums.begin(), nums.end());
//         for(int i=0; i<len; ++i){
//             if(nums[i]!=i)
//                 return i;
//         }
        
//     }
// };
//此题目感觉有问题，或测试用例有问题
//因为只缺少一个数字，只需要将原本1到n的和减去数组各个数字之和，就得到缺失的数字。
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int s = nums.size();
        int sum = s*(s + 1) / 2;
        for (int i = 0; i < s; i++)
            sum -= nums[i];
        return sum;
    }
};