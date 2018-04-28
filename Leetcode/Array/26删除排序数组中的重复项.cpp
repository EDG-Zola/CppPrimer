class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
         //在循环中调用函数nums.size()次数太多，进行优化
        int len = nums.size();
        if(len <= 1)
            return len;
       //在循环中调用函数nums.size()次数太多，进行优化,
        //比for(int i = 0; i != nums.size()-1;)从5.71提高到8.88%
        for(int i = 0; i != len-1;){
            if(nums[i] == nums[i+1]){
                nums.erase(nums.begin()+i);
                --len;
                //这里从0开始可能会很耗时间
                i=0;   
            }
            else ++i;
        }
        return nums.size();
    }
};