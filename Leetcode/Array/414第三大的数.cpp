class Solution {
public:
    int thirdMax(vector<int>& nums) {
        
        //从小到大排序
        sort(nums.begin(), nums.end());
        //删除重复元素
       vector<int>::iterator end_unique=unique(nums.begin(), nums.end());
        nums.erase(end_unique, nums.end());
        int len = nums.size();
        if(len<=0)
            return 0;
        if(len==1)
            return nums[0];
        if(len==2)
            return nums[1];
        if(len>=3)
            return nums[nums.size()-3];
    }
};