class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();
        //判断空数组的情况
        if(len == 0){
            nums.push_back(target);
            return 0;
        }
            
        for(int i = 0; i != len; ){
            if(nums[i] < target)
                ++i;
            else if(nums[i] == target)
                return i;
            else{
                
                nums.insert(nums.begin()+i, target);
                return i;
            }
        }
        //若target比所有的元素都大
        nums.push_back(target);
        return len;
        
    }
};