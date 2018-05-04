class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        int totalCount = len/2;
        // multimap<int, int> num_count;
        multiset<int> numCount(nums.begin(), nums.end());
        if(len<1)
            return 0;
        if(len == 1)
            return nums[0];
        // for(int i=0; i<len; ++i){
            //如果nums[i]在num_count中不存在，则会新建一个nums[i]键，值为对应键在nums中的下标
            //multimap不能像map使用下标进行插入元素
            //num_count[nums[i]] = i;
            // if(num_count.count(nums[i]) > totalCount)
            //     return nums[i];
            // num_count.insert(make_pair(nums[i],i));
            //}
            for(multiset<int>::const_iterator it=numCount.begin(); it!= numCount.end(); ++it){
                if(numCount.count(*it) > totalCount)
                    return *it;
            }
    }
};


//针对很长的数组，运行时间超过限制的情况下的解决方案
class Solution 
{
public:
    int majorityElement(vector<int>& nums) 
    {
        int majority = nums[0];
        int len = nums.size();
        int t = 1;
        for (int i = 1; i < len; ++i)
        {
            if (majority == nums[i])
            {
                ++t;
            }
            else
            {
                --t;
            }

            if (t == 0)
            {
                majority = nums[i];
                t = 1;
            }
        }
        return majority;
    }
};