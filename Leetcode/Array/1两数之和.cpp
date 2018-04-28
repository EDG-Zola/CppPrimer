class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        map<int, int> map_num;
        for(int index = 0; index != nums.size(); ++index){
            if(map_num.count(nums[index]) != 0){
                //exist
                result.push_back(map_num[nums[index]]);
                result.push_back(index);
            }
            map_num[target - nums[index]] = index;
        }
        return result;
    }
};